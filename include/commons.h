
namespace CAI{
    const unsigned int AFUNCTION_SIGMOID        = 0;
    const unsigned int AFUNCTION_TANH           = 2;
    const unsigned int AFUNCTION_RELU           = 2;
    const unsigned int AFUNCTION_LEAKY_RELU     = 3;
    const unsigned int AFUNCTION_SOFTMAX        = 4;
    /**
     * @brief Runs the input trough the activation function corsponding to the function input
     * @param input
     * @param function
     */
    void ActivationFunction(int input,int function);
    /**
     * @brief sigmoid function
     * @param x
     * @return 1/(1+exp(-x))
     */
    double sigmoid(double x);
    /**
     * @brief tanh function
     * @param x
     * @return (exp(x)-exp(-x))/(exp(x)+exp(-x))
     */
    double tanh(double x);
    /**
     * @brief relu function
     * @param x
     * @return x>0?x:0
     */
    double relu(double x);
    /**
     * @brief leaky relu function
     * @param x
     * @return x>0?x:0.01*x
     */
    double leaky_relu(double x);
    /**
     * @brief softmax function
     * @param x
     * @return exp(x)/(exp(x)+exp(-x))
     */
    double softmax(double x);
}