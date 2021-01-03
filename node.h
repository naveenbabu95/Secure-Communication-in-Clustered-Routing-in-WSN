

#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "leach_message_m.h"
#include <math.h>
#include <algorithm>
#include <ctime>
#include<string>
#include<cstring>
#include "ecdh.h"
#include "aes.h"
using namespace std;


static int MIN_DISTANCE = -1;
static int SEND_REDUCE = 0;
static int RECEIVE_REDUCE = 1;
static int DATA_AGGREGATION_REDUCE = 2;
static int NO_DISTANCE = 3;
static int INFO = 0;
static int DATA = 1;
static int NUM_NODES;
static double E_ELEC;
static double E_AMP;
static double E_MP;
static double E_FS;
static int THRS_DIST;
int NUM_CLUSTERS;
int CLUSTER_DEFAULT_MEMBER;
int K;
double P;

class Node : public cSimpleModule
{
  private:
    cMessage *node2headDataMessage;
    node2headMsg *node2headChooseMessage;
    cMessage *ch2baseMessage;
    cMessage *waitEvent;
    cMessage *broadcastEvent;
    cMessage *headWaitEvent;
    cMessage *nextRoundEvent;
    cModule *server, *clusterHead, *mainModule;
    cOutVector receivedRoundCountVector;
    int xPosition, yPosition, curRound, globalRound, dieCount, clusterMemberCount = 0, gDeg;
    double chDistance, battery, fullBattery, networkRadius, aggBattery, percentageControl;
    double totalExpendedEnergy;

    bool first_init = true;
    bool iAmHead = false;
    bool iAmDead = false;
    bool broadcastSent = false;
    bool littleBroadcastSent = false;
    bool chooseSent = false;
    bool broadcastArrived = false;
    bool noCh = false;
    int clustersize;
    std::string ch2headMsgStr = "";

    std::map<int,string> aggData;

    char *chFullPath = new char[128];
    char *color = new char[7];

    int * clusterMembers;
    int * clusterMembersXs;
    int * clusterMembersYs;
    double * clusterMembersBats;

    string registerationId;
    uint8_t pub[ECC_PUB_KEY_SIZE];
    uint8_t prv[ECC_PRV_KEY_SIZE];
    uint8_t sec[ECC_PRV_KEY_SIZE];
    uint8_t realsec[16];
    uint8_t basepub[ECC_PUB_KEY_SIZE];
    uint8_t cipherText[32];
    typedef struct {
        uint32_t a;
        uint32_t b;
        uint32_t c;
        uint32_t d;
    } prng_t;
    prng_t prng_ctx;
    uint8_t len = 16; //length of ciphertext in bytes
    int noOfMessagesInARound;

  protected:
    virtual void die();
    virtual void finish();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void updateDisplayStringPositionAndTag(int x, int y);
    virtual void beginHeadSelection();
    virtual void beginNextRound();
    virtual double reduceBattery(double distance, int sendOrReduce, int type, int packetCount);
    virtual int getNodeId();
    virtual uint32_t prng_rotate(uint32_t x, uint32_t k);
    virtual uint32_t prng_next(void);
    virtual void prng_init(uint32_t seed);
    virtual double getDataForNode(int n);

    virtual void printCiphers(uint8_t* str, uint8_t len);
    virtual string plaintext_padding(string plaintext,uint8_t len);
    virtual void encrypt(string strplaintext,uint8_t key[], uint8_t cipher[]);
    virtual string decrypt(uint8_t* cipher,uint8_t key[], uint8_t len);


};

double calculateDistance(int x0, int y0, int x1, int y1)
{
    return sqrt((double)( pow(abs(x0-x1), 2) + pow(abs(y0-y1), 2) ) );
}

char* generateRandomColor()
{
    char * color = new char[7];
    const char * hexa = "0123456789ABCDEF";
    color[0] = '#';
    color[1] = hexa[ intuniform(0, 15, 0) ];
    color[2] = hexa[ intuniform(0, 15, 1) ];
    color[3] = hexa[ intuniform(0, 15, 2) ];
    color[4] = hexa[ intuniform(0, 15, 3) ];
    color[5] = hexa[ intuniform(0, 15, 4) ];
    color[6] = hexa[ intuniform(0, 15, 5) ];
    return color;
}
#endif /* CALCULATIONS_H_ */
