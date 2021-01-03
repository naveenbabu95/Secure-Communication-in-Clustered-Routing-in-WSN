
network LeachBasic
{
    parameters:
        int numNodes;
        int k;
        double p;
        double eElec;
        double eAmp;
        double eFs;
        double eMp;
        double nodeBatteries;
        double thresholdDist;
        double aggregation;
        double switchPercentage;
        int maxX;
        int maxY;
        int bazX;
        int bazY;
        int clustersize

        @display("bgb=290,200,white");

    submodules:
        nd[numNodes]: Node {
            @display("p=10,10");
        }
        base: Base {
            @display("p=250,100;i=device/antennatower,,27;i2=,,61");
            numberOfLiveNodes = numNodes;
        }
}

