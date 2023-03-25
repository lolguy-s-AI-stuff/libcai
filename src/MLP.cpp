#include <MLP.h>
#include <commons.h>
namespace CAI
{
    namespace MLP
    {
    struct MlpData{//data like topology, weights and biases, activation functions, and the number of layers
        int num_layers;
        int *topology;
        double **weights;
        double **biases;
        int activation_function;
    }
       
   
    void Run(const char* input,MlpData model,const char* out_to_here,int num_inputs){
        double **neuron_values;
        toreturn.neuron_values = malloc(sizeof(double*)*model.num_layers);
        //1. check if the input is the right length
        if (num_inputs != model.topology[0]){
            printf("Error: input length is not the same as the first layer's length\n");
            return;
        }

        //2. loop trough the layers and calculate the neurons, and store them in neuron_values
        for (size_t i = 0; i < model.num_layers; i++)
        {
            neuron_values[i] = malloc(sizeof(double)*model.topology[i]);

            for (size_t j = 0; j < model.topology[i]; j++)
            {

                if (i == 0){//if we are calculating the first layer
                //calculate this neuron using the inputs
                    model.neuron_values[i][j] = input[j]*model.weights[i][j] + model.biases[i][j];
                }else{//if we are NOT calculating the first layer
                //calculate this neuron using the previous layer
                    double sum = 0;
                    for (size_t k = 0; k < model.topology[i-1]; k++)
                    {
                        sum += model.neuron_values[i-1][k]*model.weights[i][k*model.topology[i]+j];
                    }
                    // put the result trough the provided activation function and store it as this neuron's value
                    model.neuron_values[i][j] = CAI::ActivationFunction(sum + model.biases[i][j],model.activation_function);
                }
            
            }
        }
         
        //3. copy the output to out_to_here
        for (size_t i = 0; i < model.topology[model.num_layers-1]; i++)
        {
            out_to_here[i] = model.neuron_values[model.num_layers-1][i];
        }
        
        //4. free shit
        free(tofree.neuron_values);
    }       

    MlpData CreateEmpty(int num_layers,int *topology){//create an MlpData struct with all zeroes as weights and biases
        MlpData toreturn;
        toreturn.num_layers = num_layers;
        toreturn.topology = topology;
        toreturn.weights = malloc(sizeof(double*)*num_layers);
        toreturn.biases = malloc(sizeof(double*)*num_layers);
        toreturn.activation_functions = malloc(sizeof(int)*num_layers)
        for (size_t i = 0; i < num_layers; i++)
        {
            toreturn.weights[i] = malloc(sizeof(double)*topology[i]*topology[i+1]);
            toreturn.biases[i] = malloc(sizeof(double)*topology[i+1]);
            
            for (size_t j = 0; j < topology[i]*topology[i+1]; j++)
            {
                toreturn.weights[i][j] = 0;
            }
            for (size_t j = 0; j < topology[i+1]; j++)
            {
                toreturn.biases[i][j] = 0;
            }
        }
        return toreturn;
    }
        /**
     * @brief Create a MlpData with random weights and biases
     * @param num_layers number of layers
     * @param topology array of int containing the number of neurons in each layer
     * @return a MlpData with random weights and biases
     */
    MlpData CreateRandom(int num_layers,int *topology){
        MlpData toreturn;
        toreturn.num_layers = num_layers;
        toreturn.topology = topology;
        toreturn.weights = malloc(sizeof(double*)*num_layers);
        toreturn.biases = malloc(sizeof(double*)*num_layers);
        toreturn.activation_functions = malloc(sizeof(int)*num_layers)
        for (size_t i = 0; i < num_layers; i++)
        {
            toreturn.weights[i] = malloc(sizeof(double)*topology[i]*topology[i+1]);
            toreturn.biases[i] = malloc(sizeof(double)*topology[i+1]);
            
            for (size_t j = 0; j < topology[i]*topology[i+1]; j++)
            {
                toreturn.weights[i][j] = rand()%10 / 10.0;
            }
            for (size_t j = 0; j < topology[i+1]; j++)
            {
                toreturn.biases[i][j] = rand()%10 / 10.0;
            }
        }
        return toreturn;
    }

    MlpData CreateFromFile(const char* filename,int num_layers,int *topology){
        MlpData toreturn;
        toreturn.num_layers = num_layers;
        toreturn.topology = topology;
        toreturn.weights = malloc(sizeof(double*)*num_layers);
        toreturn.biases = malloc(sizeof(double*)*num_layers);
        toreturn.activation_functions = malloc(sizeof(int)*num_layers)
        FILE *file = fopen(filename,"r");
        if (file == NULL){
            printf("Error: file could not be opened\n");
            return toreturn;
        }
        for (size_t i = 0; i < num_layers; i++)
        {
            toreturn.weights[i] = malloc(sizeof(double)*topology[i]*topology[i+1]);
            toreturn.biases[i] = malloc(sizeof(double)*topology[i+1]);
            
            for (size_t j = 0; j < topology[i]*topology[i+1]; j++)
            {
                fscanf(file,"%lf",&toreturn.weights[i][j]);
            }
            for (size_t j = 0; j < topology[i+1]; j++)
            {
                fscanf(file,"%lf",&toreturn.biases[i][j]);
            }
        }
        fclose(file);
        return toreturn;
    }
    void SaveToFile(const char* filename,MlpData model,int num_layers,int *topology){
        FILE *file = fopen(filename,"w");
        if (file == NULL){
            printf("Error: file could not be opened\n");
            return;
        }
        for (size_t i = 0; i < num_layers; i++)
        {
            fprintf(file,"%d\n",topology[i]);
            for (size_t j = 0; j < topology[i]*topology[i+1]; j++)
            {
                fprintf(file,"%lf\n",model.weights[i][j]);
            }
            for (size_t j = 0; j < topology[i+1]; j++)
            {
                fprintf(file,"%lf\n",model.biases[i][j]);
            }
        }
        fclose(file);
    }

    void EditWeight(MlpData model, int layer,int address,int value){//edit a weight,but only if its in bounds to prevent buffer overflows

    //1. check if the weight is in bounds
        if (layer >= model.num_layers || address >= model.topology[layer]*model.topology[layer+1]){
            printf("Error: weight is out of bounds\n");
            return;
        }

    //2. set the weight
        model.weights[layer][address] = value;
    }
    void EditBias(MlpData model, int layer,int address,int value){//edit a bias,but only if its in bounds to prevent buffer overflows
    //1. check if the bias is in bounds
        if (layer >= model.num_layers || address >= model.topology[layer+1]){
            printf("Error: bias is out of bounds\n");
            return;
        }

    //2. set the bias
        model.biases[layer][address] = value;
    }
    void Free(MlpData tofree){//free all the allocated memory in tofree
        for (size_t i = 0; i < tofree.num_layers; i++)
        {
            free(tofree.weights[i]);
            free(tofree.biases[i]);
            free(tofree.neuron_values[i]);
        }
        free(tofree.weights);
        free(tofree.biases);
        free(tofree.activation_functions);
        free(tofree.topology);

    }
    } // namespace MLP

}