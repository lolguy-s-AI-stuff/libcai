namespace CAI
{
    namespace MLP
    {
    struct MlpData{//data like topology, weights and biases, activation functions
        int num_layers;
        int *topology;
        double **weights;
        double **biases;
        int *activation_functions;
    }
    void Run(const char* input,MlpData model,const char* out_to_here);        

    MlpData CreateEmpty(int num_layers,int *topology);

    void EditWeight(MlpData model, int layer,int address,int value);
    void EditBias(MlpData model, int layer,int address,int value);

    void Free(MlpData tofree);
    }

}