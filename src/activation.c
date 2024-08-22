#include <math.h>

#include "activation.h"

double sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x)
{
    double sig = sigmoid(x);

    return sig * (1.0 - sig);
}