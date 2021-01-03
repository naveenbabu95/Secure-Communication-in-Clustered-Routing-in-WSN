
cplusplus {{
#include <map>
#include<string>
using namespace std;
typedef std::map<int, string> mapForData;
}};

class noncobject mapForData;

message node2headMsg
{
    int source;
    int posX;
    int posY;
    bool die;
    double battery;
    string temperature;
}

message head2baseMsg
{
    bool die;
    int source;
    int posX;
    int posY;
    string mes;
    int dieCount;
    mapForData aggregatedData;
    double totalExpendedEnergy = 0.0; 
}

message broadcastMsg
{
    int posX;
    int posY;
    string color;
    string chFullPath;
    int CHNodeNo;
}
message bsInitbroadcastMsg
{
 	uint8_t publicKey[48];     
}
message littleBroMsg
{
    int posX;
    int posY;
    int chNo;
    int chPosX;
    int chPosY;
    string chFullPath;
    string color;
}

message Node2BaseMsg
{
    int source;
    int posX;
    int posY;
    double battery;
    string hash;
    string purpose;
    string timestamp;
    uint8_t nodepublickey[48]; 
}


