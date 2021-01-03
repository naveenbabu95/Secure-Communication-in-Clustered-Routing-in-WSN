
simple Base
{
    parameters:
        @display("i=device/wifilaptop;is=l;i2=block/plug_vs");
        int numberOfLiveNodes;
        int receivedMessageCount = 0;
        
        string regid0;
		string regid1;
		string regid2;
		string regid3;
		string regid4;
		string regid5;
		string regid6;
		string regid7;
		string regid8;
		string regid9;
		
		int staleThreshold;
    gates:
        input in @directIn @loose;
        output out @diretOut @loose;
}
