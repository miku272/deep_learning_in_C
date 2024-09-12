#include <math.h>

// #include "activation.h"
#include "../include/activation.h"

double sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x)
{
    double sig = sigmoid(x);

    return sig * (1.0 - sig);
}

double relu(double x)
{
    return x > 0.0 ? x : 0.0;
}

double relu_derivative(double x)
{
    return x > 0.0 ? 1.0 : 0.0;
}