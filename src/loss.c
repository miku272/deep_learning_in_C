#include <stdlib.h>
#include <math.h>

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

double cross_entropy_loss(const double *actual, const double *predicted, size_t length)
{
    double loss = 0;

    for (size_t i = 0; i < length; i++)
    {
        loss += -actual[i] * log(predicted[i]) - (1 - actual[i]) * log(1 - predicted[i]);
    }
}

void cross_entropy_loss_derivative(const double *actual, const double *predicted, double *gradient, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        gradient[i] = -((actual[i] / predicted[i]) - (1.0 - actual[i]) / (1.0 - predicted[i])) / length;
    }
}