
simple Node
{
    parameters:
        double battery;
        string registerationId;
        
    gates:
        input in @diretIn @loose;
        output out @diretOut @loose;
}
