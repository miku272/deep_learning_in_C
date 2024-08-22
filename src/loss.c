#include <stdio.h>
#include <stdlib.h>

#include "loss.h"

double mean_squared_error(const double *actual, const double *predicted, size_t length)
{
    double sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += (actual[i] - predicted[i]) * (actual[i] - predicted[i]);
    }
    return sum / length;
}

void mean_squared_error_derivative(const double *actual, const double *predicted, double *gradient, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        gradient[i] = -2.0 * (actual[i] - predicted[i]) / length;
    }
}