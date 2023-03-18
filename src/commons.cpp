#include <stdio.h>
#include <cmath>
#include <commons.h>
namespace CAI{
    void ActivationFunction(int input,int function){
        switch (function)
        {
        case 0:
            return sigmoid(input);
        case 1:
            return tanh(input);
        case 2:
            return relu(input);
        case 3:
            return leaky_relu(input);
        case 4:
            return softmax(input);
        
        default:
            printf("[Error]:there is no such activation function function(%i)",function);
        }
    }
    double sigmoid(double x){
        return 1/(1+exp(-x));
    }
    double tanh(double x){
        return (exp(x)-exp(-x))/(exp(x)+exp(-x));
    }
    double relu(double x){
        return x>0?x:0;
    }
    double leaky_relu(double x){
        return x>0?x:0.01*x;
    }
    double softmax(double x){
        return exp(x)/(exp(x)+exp(-x));
    }
}