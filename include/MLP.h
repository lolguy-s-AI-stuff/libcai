namespace CAI
{
    namespace MLP
    {
    /// \brief A struct that holds the data of a MLP
    struct MlpData{
        int num_layers;
        int *topology;
        double **weights;
        double **biases;
        int activation_function;
    }

    /**
     * @brief Run the neural network
     * @param input The input of the neural network
     * @param model The model 
     * @param out_to_here The output of the neural network
     * @param num_inputs The number of inputs
     */
    void Run(const char* input,MlpData model,const char* out_to_here,int num_inputs);

    /**
     * @brief Create an empty MlpData
     * @param num_layers number of layers
     * @param topology array of int containing the number of neurons in each layer
     * @return an empty MlpData
     */
    MlpData CreateEmpty(int num_layers,int *topology);

    /**
     * @brief Create a MlpData with random weights and biases
     * @param num_layers number of layers
     * @param topology array of int containing the number of neurons in each layer
     * @return a MlpData with random weights and biases
     */
    MlpData CreateRandom(int num_layers,int *topology);

    /**
     * @brief Create a MlpData from a file
     * @param filename The name of the file
     * @param num_layers number of layers
     * @param topology array of int containing the number of neurons in each layer
     * @return a MlpData
     * @warning The file must be in the correct format
     */
    MlpData CreateFromFile(const char* filename,int num_layers,int *topology);

    /**
     * @brief Save the MlpData to a file
     * @param filename The name of the file
     * @param model The model
     * @param num_layers number of layers
     * @param topology array of int containing the number of neurons in each layer
     * @warning The file must not exist
    */
    void SaveToFile(const char* filename,MlpData model,int num_layers,int *topology);

    /**
     * @brief Edit a weight of the MlpData
     * @param model the MlpData to edit
     * @param layer the layer of the weight
     * @param address the address of the weight
     * @param value the new value of the weight
     */
    void EditWeight(MlpData model, int layer,int address,int value);

    /**
     * @brief Edit a bias of the MlpData
     * @param model the MlpData to edit
     * @param layer the layer of the bias
     * @param address the address of the bias
     * @param value the new value of the bias
     */
    void EditBias(MlpData model, int layer,int address,int value);

    /**
     * @brief Free the MlpData
     * @param tofree the MlpData to free
     */
    void Free(MlpData tofree);
    }

}