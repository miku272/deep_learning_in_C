#ifndef BACKWARD_PROP_C
#define BACKWARD_PROP_C

#include <stdio.h>
#include <stdlib.h>

#include "../include/backward_prop.h"

#include "matrix.c"
#include "activation.c"
#include "loss.c"

void backward_prop(Layer **layers, size_t n_layers, double **inputs, double **targets, size_t n_samples, double learning_rate)
{
    // Initialize a matrix to hold the errors for each layer
    Matrix *errors = (Matrix *)malloc(n_layers * sizeof(Matrix));

    // Compute the error at the output layer
    Layer *output_layer = layers[n_layers - 1];
    errors[n_layers - 1] = create_matrix(n_samples, output_layer->n_neurons);

    for (size_t i = 0; i < n_samples; i++)
    {
        for (size_t j = 0; j < output_layer->n_neurons; j++)
        {
            // double y_pred = output_layer->
        }
    }
}

#endif