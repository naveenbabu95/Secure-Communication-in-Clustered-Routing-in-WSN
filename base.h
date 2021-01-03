
#ifndef BASE_H_
#define BASE_H_

#include <stdio.h>
#include <omnetpp.h>
#include<vector>
#include<string>
#include<cstring>
#include <ctime>
#include<string>
#include "leach_message_m.h"
#include "ecdh.h"
#include "BSFiles/Baes.h"

using namespace std;

class Base: public cSimpleModule {
private:
    int clusterMaxMember;
    int numNodes;
    int numClusters;
    int clustersize;
    double p;
    cModule *mainModule;
    int xPosition, yPosition;
    int receivedRoundCount;
    int numberOfLivingNodes;
    bool * nodeDeaths;
    bool noEnergy = false;
    int * posXs;
    int * posYs;
    double * nodeBatteries;
    double expendedEnergyForRound;
    double totalExpendedEnergy;
    cLongHistogram numberOfLivingNodesStats;
    cLongHistogram receivedRoundCountStats;
    cLongHistogram expendedEnergiesForRoundsStats;
    cOutVector expendedEnergiesForRoundsVector;
    cOutVector numberOfLivingNodesVector;
    cOutVector receivedRoundCountVector;
    cOutVector totalEnergyVector;

    cMessage *broadcastEvent;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    map<int, string> mapregid;
    int staleThreshold; //in secs
    int holdElection;
    cMessage *chooseLeader;
    uint8_t pub[ECC_PUB_KEY_SIZE];
    uint8_t prv[ECC_PRV_KEY_SIZE];
    map<int, string> secrets;
    uint8_t len = 16;
    typedef struct {
        uint32_t a;
        uint32_t b;
        uint32_t c;
        uint32_t d;
    } prng_t;
    prng_t prng_ctx;
    int noOfMessagesInARound;
    int noofRound;
    cMessage *baseInitEvent;

protected:
    virtual void initialize();
    virtual void finish();
    virtual void handleMessage(cMessage *msg);
    virtual void ChooseLeader();
    virtual bool isStale(string timestamp);
    virtual uint32_t prng_rotate(uint32_t x, uint32_t k);
    virtual uint32_t prng_next(void);
    virtual void prng_init(uint32_t seed);
    virtual void nextRound();
    virtual void ContinueComptation(int src);
    virtual void printCiphers(uint8_t* str, uint8_t len);
    virtual string plaintext_padding(string plaintext,uint8_t len);
    virtual void encrypt(string strplaintext,uint8_t key[], uint8_t cipher[]);
    virtual string decrypt(uint8_t* cipher,uint8_t key[], uint8_t len);
};

#endif /* BASE_H_ */

