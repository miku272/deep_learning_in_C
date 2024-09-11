#include <stdio.h>
#include <stdlib.h>

#include "../include/ann.h"

#include "matrix.c"

Layer *create_layer(size_t n_inputs, size_t n_neurons)
{
    Layer *layer = (Layer *)malloc(sizeof(Layer));
    layer->n_inputs = n_inputs;
    layer->n_neurons = n_neurons;

    layer->weights = create_matrix(n_inputs, n_neurons);

    layer->biases = (double *)malloc(n_neurons * sizeof(double));

    // Initializing the weight for the first time randomly
    for (int i = 0; i < n_inputs * n_neurons; i++)
    {
        layer->weights.data[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Note: If we just use 1.0, the range would be 0.0 to 1.0, not -1.0 to 1.0
    }

    for (int i = 0; i < n_neurons; i++)
    {
        layer->biases[i] = 0.0; // No biases at start
    }

    return layer;
}

void free_layer(Layer *layer)
{
    free_matrix(&layer->weights);
    free(layer->biases);
    free(layer);
}

void forward_layer(Layer *layer, double **input, double **output, size_t n_samples)
{
    for (size_t i = 0; i < n_samples; i++)
    {
        for (size_t j = 0; j < layer->n_neurons; j++)
        {
            output[i][j] = layer->biases[j];

            for (size_t k = 0; k < layer->n_inputs; k++)
            {
                output[i][j] += input[i][k] * layer->weights.data[k * layer->n_neurons + j]; // Note: Weights are stored in column-major order and We are doing matrix multiplication here.
            }
        }
    }
}