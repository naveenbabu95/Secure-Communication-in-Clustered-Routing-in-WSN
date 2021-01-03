

#include "base.h"
#include "sha256.h"
#include "ecdh.h"
#include "BSFiles/Baes.h"
#include "BSFiles/Baes.c"

#define MessagesInARound 3
#define Rounds 4
#if defined(AES256)
    uint8_t cipherlen = 32;
#elif defined(AES192)
    uint8_t cipherlen = 24;
#elif defined(AES128)
    uint8_t cipherlen = 16;
#endif

Define_Module(Base);

////////////////////////////////////PRNG//////////////
uint32_t Base::prng_rotate(uint32_t x, uint32_t k) {
    return (x << k) | (x >> (32 - k));
}

uint32_t Base::prng_next(void) {
    uint32_t e = prng_ctx.a - prng_rotate(prng_ctx.b, 27);
    prng_ctx.a = prng_ctx.b ^ prng_rotate(prng_ctx.c, 17);
    prng_ctx.b = prng_ctx.c + prng_ctx.d;
    prng_ctx.c = prng_ctx.d + e;
    prng_ctx.d = e + prng_ctx.a;
    return prng_ctx.d;
}

void Base::prng_init(uint32_t seed) {
    uint32_t i;
    prng_ctx.a = 0xf1ea5eed;
    prng_ctx.b = prng_ctx.c = prng_ctx.d = seed;

    for (i = 0; i < 31; ++i) {
        (void) prng_next();
    }
}

void Base::nextRound() {
    if(false) {
        finish();
    }
    else{
       noofRound++;
       srand(time(NULL));
       static int initialized = 0;
       if (!initialized) {
           prng_init(rand());
//           initialized = 1;
       }

       noOfMessagesInARound = 2*MessagesInARound +1;
       for (int i = 0; i < ECC_PRV_KEY_SIZE; ++i) {
           prv[i] = prng_next();
       }

       ecdh_generate_keys(pub, prv);

       bsInitbroadcastMsg * initmsg = new bsInitbroadcastMsg("bsinitmsg");
       for (int i = 0; i < ECC_PUB_KEY_SIZE; i++)
           initmsg->setPublicKey(i, pub[i]);
       char *chr = new char[numNodes];
       EV<<"Public key of base is ";
       for (int i=0;i<ECC_PUB_KEY_SIZE;i++){
           EV<<pub[i];
       }
       EV<<"\n";

       for (int i=0;i<numNodes;i++){
           sprintf(chr, "LeachBasic.nd[%d]", i);
           sendDirect(initmsg->dup(), getModuleByPath(chr), "out");
       }
   }
}

//encryption - AES
void Base::printCiphers(uint8_t* str, uint8_t len)
{
    unsigned char i;
    for (i = 0; i < len; ++i) {
        printf("%.2x", str[i]);
        EV<<str[i];
    }
    printf("\n");
    EV<<"\n";
}

string Base::plaintext_padding(string plaintext,uint8_t len) {
    string str = plaintext;
    str.resize(len,'0');
    if(plaintext.size() < len) {
        str[plaintext.size()] = '1';
    }
    return str;
}

void Base::encrypt(string strplaintext,uint8_t key[], uint8_t cipher[]) {
    uint8_t len = cipherlen;
    std::vector<uint8_t> myVector(strplaintext.begin(), strplaintext.end());
    uint8_t *plain_text = &myVector[0];
//    phex(plain_text, len);
    struct BAES_ctx ctx1;
    BAES_init_ctx(&ctx1, key);
    BAES_ECB_encrypt(&ctx1, plain_text);
    for(int i=0;i<len;i++) {
        cipher[i] = plain_text[i];
    }
}

string Base::decrypt(uint8_t* cipher,uint8_t key[], uint8_t len1) {
    struct BAES_ctx ctx2;

//    EV<<"key is ";
    uint8_t realsec[len];
    for(auto i=0;i<len;i++){
//        EV<<key[i];
        realsec[i] = key[i];
    }
//    printCiphers(realsec, len);
//    EV<<"\n\n";
    BAES_init_ctx(&ctx2, realsec);
    BAES_ECB_decrypt(&ctx2, cipher);
    string a = "";
    a = (char*)cipher;
    a = a.substr(0,len);
//    int count = 0;
//    for(auto i=a.size()-1;a[i];i--) {
//        if(a[i] =='1')
//            break;
//        count++;
//    }
//    a.resize((int)a.size()-count-1);
//    printf(a.c_str());
    return a.c_str();
}


////////////////////////////////////////////////////
void Base::initialize() {

    mainModule = getModuleByPath("LeachBasic");
    p = mainModule->par("p").doubleValue();
    numNodes = mainModule->par("numNodes");
    clustersize = mainModule->par("clustersize");
    clusterMaxMember = (int) (1 / p);
    numClusters = (numNodes / clusterMaxMember);
    noofRound = 0;
    noOfMessagesInARound = 2*MessagesInARound +1;
    numberOfLivingNodes = numNodes;
    receivedRoundCount = 0;
    totalExpendedEnergy = 0;
    nodeDeaths = new bool[numNodes];
    nodeBatteries = new double[numNodes];
    staleThreshold = par("staleThreshold");
    //store mapping
    for (int i = 0; i < numNodes; i++) {
        string name = "regid" + to_string(i);
        const char * a = name.c_str();
        string temp = par(a);
        mapregid.insert( { i, temp });
    }
    holdElection = 1;
    chooseLeader = new cMessage("chooseLeader");

    double ndbt = mainModule->par("nodeBatteries");

    for (int i = 0; i < numNodes; i++) {
        nodeDeaths[i] = false;
        nodeBatteries[i] = ndbt;
    }

    WATCH(numberOfLivingNodes);
    WATCH(receivedRoundCount);

    char* str = new char[16];
    xPosition = mainModule->par("bazX");
    yPosition = mainModule->par("bazY");
    sprintf(str, "BS (%d, %d)", xPosition, yPosition);
    getDisplayString().setTagArg("t", 0, str);
    getDisplayString().setTagArg("p", 0, xPosition);
    getDisplayString().setTagArg("p", 1, yPosition);

    totalEnergyVector.setName("Total Energy Vector");
    numberOfLivingNodesVector.setName("Number Of Living Nodes Vector");
    receivedRoundCountVector.setName("Received Round Count Vector");
    expendedEnergiesForRoundsVector.setName(
            "Expended Energies For Rounds Vector");

    totalEnergyVector.record(totalExpendedEnergy);
    numberOfLivingNodesVector.record(numberOfLivingNodes);
    receivedRoundCountVector.record(receivedRoundCount);
    expendedEnergiesForRoundsVector.record(0.0);

    srand(time(NULL));
    static int initialized = 0;
    if (!initialized) {
        prng_init(rand());
        initialized = 1;
    }


    for (int i = 0; i < ECC_PRV_KEY_SIZE; ++i) {
        prv[i] = prng_next();
    }

    ecdh_generate_keys(pub, prv);

    baseInitEvent = new cMessage("BSInitEvent");
    cancelEvent(baseInitEvent);
    scheduleAt(simTime() + 1.0, baseInitEvent);



}
bool Base::isStale(string timestamp) {
    const char *T = timestamp.c_str();
    int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;

    if (sscanf(T, "%4d%2d%2d%2d%2d%2d", &year, &month, &day, &hour, &min, &sec)
            == 6) {
        struct tm breakdown = { 0 };
        breakdown.tm_year = year - 1900; /* years since 1900 */
        breakdown.tm_mon = month - 1;
        breakdown.tm_mday = day;
        breakdown.tm_hour = hour;
        breakdown.tm_min = min;
        breakdown.tm_sec = sec;
        time_t now;
        time(&now);
        double seconds = difftime(now, mktime(&breakdown));
        if (seconds <= staleThreshold) {
            return false;
        }
    }
    return true;

}

void Base::ChooseLeader() {
    cancelEvent(chooseLeader);
    double max = 0.0;
    int leader;
    char *chr = new char[clustersize];
    for (int i = 0; i < clustersize; i++) {
        if (max < nodeBatteries[i]) {
            max = nodeBatteries[i];
            leader = i;
        }
    }

    broadcastMsg *bcmsg;
    broadcastEvent = new cMessage("bcMElection");
    bcmsg = new broadcastMsg("bcMElection");
    bcmsg->setPosX(xPosition);
    bcmsg->setPosY(yPosition);
    bcmsg->setKind(2); // BLUE DOT
    bcmsg->setCHNodeNo(leader);
    broadcastEvent = check_and_cast<cMessage *>(bcmsg);
    for (int i = 0; i < clustersize; i++) {
        sprintf(chr, "LeachBasic.nd[%d]", i);
        sendDirect(broadcastEvent->dup(), getModuleByPath(chr), "in");
    }
    v1.clear();

    //for cluster 2
    max = 0.0;
    for (int i = clustersize; i < numNodes; i++) {
        if (max < nodeBatteries[i]) {
            max = nodeBatteries[i];
            leader = i;
        }
    }

//     broadcastMsg *bcmsg;
    broadcastEvent = new cMessage("bcMElection");
    bcmsg = new broadcastMsg("bcMElection");
    bcmsg->setPosX(xPosition);
    bcmsg->setPosY(yPosition);
    bcmsg->setKind(2); // BLUE DOT
    bcmsg->setCHNodeNo(leader);
    char *chr1 = new char[clustersize];
    broadcastEvent = check_and_cast<cMessage *>(bcmsg);
    for (int i = clustersize; i < numNodes; i++) {
        sprintf(chr1, "LeachBasic.nd[%d]", i);
        sendDirect(broadcastEvent->dup(), getModuleByPath(chr1), "in");
    }
    cancelEvent(broadcastEvent);
    v2.clear();
    v3.clear();
    v4.clear();

}
void Base::ContinueComptation(int src) {
    if (src < clustersize) {
        v3.push_back(src);
    } else {
        v4.push_back(src);
    }
    if (holdElection == 1) {
        holdElection = 0;


    }
    int size1 = v1.size();
    int size2 = v2.size();
    int size3 = v3.size();
    int size4 = v4.size();
    if ((size1+size3 == clustersize) && (size2+size4 == clustersize)) {
        ChooseLeader();
    }

}
void Base::handleMessage(cMessage *msg) {
    EV<<msg->getName();
    if(strcmp(msg->getName(), "BSInitEvent") == 0) {
        bsInitbroadcastMsg * initmsg = new bsInitbroadcastMsg("bsinitmsg");
        for (int i = 0; i < ECC_PUB_KEY_SIZE; i++)
            initmsg->setPublicKey(i, pub[i]);
        char *chr = new char[numNodes];
        EV<<"Public key of base is ";
        for (int i=0;i<ECC_PUB_KEY_SIZE;i++){
            EV<<pub[i];
        }
        EV<<"\n";

        for (int i=0;i<numNodes;i++){
            sprintf(chr, "LeachBasic.nd[%d]", i);
            sendDirect(initmsg->dup(), getModuleByPath(chr), "out");
        }
        noofRound++;
    }
    else if (strcmp(msg->getName(), "SetupPhase") == 0) {

        Node2BaseMsg *msg3 = check_and_cast<Node2BaseMsg *>(msg);

        uint8_t arr[ECC_PUB_KEY_SIZE];
        for(int i = 0;i<ECC_PUB_KEY_SIZE;i++)
           arr[i] = msg3->getNodepublickey(i);
        uint8_t arr1[ECC_PUB_KEY_SIZE];
        ecdh_shared_secret(prv,arr,arr1);
//        uint8_t arr2[ECC_PRV_KEY_SIZE-1];
//        for(int i=0;i<ECC_PRV_KEY_SIZE-1;i++){
//            arr2[i] = arr1[i];
//        }
        string a = "";
        a = (char*)arr1;
        secrets[msg3->getSource()] = a;
//        secrets.insert({msg3->getSource(), arr2});
//        EV<<"Length of "<<ECC_PRV_KEY_SIZE;
        EV<<"\nSecret for base for node "<<msg3->getSource()<<" ";
//        uint8_t needtoprint[ECC_PRV_KEY_SIZE];
//        needtoprint = secrets[msg3->getSource()];
//        for(int i=0;i<ECC_PRV_KEY_SIZE;i++){
//            EV<<arr2[i];
//        }
        EV<<secrets[msg3->getSource()];
        EV<<"\n";
        noEnergy = false;
        int src = msg3->getSource();
        double olddd = nodeBatteries[src];
        nodeBatteries[src] = msg3->getBattery();
        expendedEnergyForRound += (olddd - nodeBatteries[src]);
        string timestamp = msg3->getTimestamp();
        if (!isStale(timestamp)) {
            if (strcmp(msg3->getPurpose(), "Election") == 0) {
                string regid = mapregid[src];
                string result = regid;
                for (int i = 0; i < regid.size(); i++) {
                    result[i] = regid[i] ^ timestamp[i];
                }
                result.pop_back();
                string hash1 = sha256(result);
                hash1 = hash1.substr(0,len);
//                EV<<"After computation "<<hash1;
                string hashorg = msg3->getHash();
//                EV<<"hash of nd"<<msg3->getSource()<<" is "<<hashorg<<"\n";
                std::vector<uint8_t> myVector2(hashorg.begin(), hashorg.end());
                uint8_t *c = &myVector2[0];
                string a = secrets[msg3->getSource()];
                std::vector<uint8_t> myVector1(a.begin(), a.end());
                uint8_t *h = &myVector1[0];
                hashorg = decrypt(c, h, cipherlen);
//                EV<<"After dect "<<hashorg<<"\n";

                if (hash1.compare(hashorg) == 0) {

                    if (src < clustersize) { //cluster 1
                        v1.push_back(src);
                    } else {
                        v2.push_back(src);
                    }
//                    EV << holdElection;
                    if (holdElection == 1) {
                        holdElection = 0;


                    }
                    int size1 = v1.size();
                    int size2 = v2.size();
                    int size3 = v3.size();
                    int size4 = v4.size();
                    if ((size1+size3 == clustersize) && (size2+size4 == clustersize)) {
                        ChooseLeader();
                    }
                }
                else {
                       ContinueComptation(src);
                }
            }
        }
    }

    else if (strcmp(msg->getName(), "chooseLeader") == 0) {
        holdElection = 1;
        ChooseLeader();

    }

    else {
        if (strcmp(msg->getName(), "recordEnergy") == 0) {
            if (noEnergy) {
                EV
                          << "NO MORE INFORMATION, SIMULATION IS STOPPING!!!!!!!!XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
                return;
            }
            EV
                      << "RECORDING =======================================XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  "
                      << expendedEnergyForRound << "    XXXXXXXXXX\n";
            expendedEnergiesForRoundsVector.record(expendedEnergyForRound);
            // expendedEnergyForRound = .0;
            noEnergy = true;
//            scheduleAt(simTime()+4, msg);
            return;
        }

        head2baseMsg *msg1 = check_and_cast<head2baseMsg *>(msg);
        if (strcmp(msg->getName(), "die") == 0
                && nodeDeaths[msg1->getSource()] == false) {

            nodeDeaths[msg1->getSource()] = true;
            numberOfLivingNodes--;
            numberOfLivingNodesVector.record(numberOfLivingNodes);
            return;
        }

        if (strcmp(msg->getName(), "myBattery") == 0) {
            //        head2baseMsg *msg1 = check_and_cast<head2baseMsg *>(msg);
            noEnergy = false;
            int src = msg1->getSource();
            double olddd = nodeBatteries[src];
            nodeBatteries[src] = msg1->getTotalExpendedEnergy();
            expendedEnergyForRound += (olddd - nodeBatteries[src]);
        }

        if (strcmp(msg1->getName(), "h2bM") == 0) { // Message arrived.
            //        head2baseMsg *msg1 = check_and_cast<head2baseMsg *>(msg);
//            EV << "BASE: Message " << msg->getName() << " arrived from node["
//                      << msg->getSenderModuleId() - 2 << "].\n";
//            EV << "BASE: RECEIVED DIE COUNT : " << msg1->getDieCount()
//                      << " *********************************************************************.\n";
            bubble("ARRIVED");


            map<int,string> dataRecieved;
            dataRecieved = msg1->getAggregatedData();
            if(dataRecieved.size()>0){
                EV<<"What BS received from node"<<msg1->getSource()<< "\n";
                for(auto i=dataRecieved.begin();i!=dataRecieved.end();i++) {
                    EV<<i->first<<"\t"<<i->second<<"\n";
                }
                EV<<"After Decryption\n";
                for(auto i=dataRecieved.begin();i!=dataRecieved.end();i++) {
                    std::vector<uint8_t> myVector(i->second.begin(), i->second.end());
                    uint8_t *c = &myVector[0];
                    EV<<i->first<<"\t";
                    string a = secrets[i->first];
                    std::vector<uint8_t> myVector1(a.begin(), a.end());
                    uint8_t *h = &myVector1[0];
                    EV<<decrypt(c, h, cipherlen)<<"\n";
                }
            }


            EV<<"messages in a round"<<noOfMessagesInARound<<"\n";
            noOfMessagesInARound--;
            if(noOfMessagesInARound >= 0 ) {
            }
            else {
                noOfMessagesInARound = 2*MessagesInARound + 1;
                nextRound();
            }

        }
    }
    delete msg;
}

void Base::finish() {
    receivedRoundCountVector.record(receivedRoundCount / numClusters);
    recordScalar("#receivedRoundCount", receivedRoundCount);
    numberOfLivingNodesStats.recordAs("Number of Living Nodes");
    receivedRoundCountStats.recordAs("Recevied Message Count");
}

