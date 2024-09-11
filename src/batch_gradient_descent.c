#include "../include/batch_gradient_descent.h"

void batch_gradient_descent(double **weights, double *biases, double **dw, double *db, size_t n_features, size_t n_neurons, double learning_rate)
{
    for (size_t j = 0; j < n_neurons; j++)
    {
        for (size_t i = 0; i < n_features; i++)
        {
            weights[i][j] -= learning_rate * dw[i][j];
        }
    }

    for (size_t i = 0; i < n_neurons; i++)
    {
        biases[i] -= learning_rate * db[i];
    }
}