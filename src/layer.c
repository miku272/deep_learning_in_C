#ifndef LAYER_C
#define LAYER_C

#include <stdio.h>
#include <stdlib.h>

// #include "ann.h"
#include "../include/layer.h"

// #include "matrix.h"
#include "matrix.c"
// #include "activation.h"
#include "activation.c"

Layer create_layer(size_t n_inputs, size_t n_neurons)
{
    Layer *layer = (Layer *)malloc(sizeof(Layer));
    layer->n_inputs = n_inputs;
    layer->n_neurons = n_neurons;

    layer->weights = create_matrix(n_inputs, n_neurons);

    layer->biases = (double *)malloc(n_neurons * sizeof(double));

    // Initializing the weight for the first time randomly
    for (size_t i = 0; i < n_inputs * n_neurons; i++)
    {
        layer->weights.data[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Note: If we just use 1.0, the range would be 0.0 to 1.0, not -1.0 to 1.0
    }

    for (size_t i = 0; i < n_neurons; i++)
    {
        layer->biases[i] = 0.0; // No biases at start
    }

    return *layer;
}

void free_layer(Layer *layer)
{
    free_matrix(&layer->weights);
    free(layer->biases);
    free(layer);
}

Matrix forward_layer(Layer *layer, Matrix input_data, int is_output_layer)
{
    // Perform matrix multiplication to get the pre-activation (Z = XW)
    Matrix pre_activation = matrix_multiply(&input_data, &layer->weights);

    // Add bias and apply activation function
    for (size_t sample = 0; sample < input_data.rows; sample++)
    {
        for (size_t neuron = 0; neuron < layer->n_neurons; neuron++)
        {
            // Add bias
            pre_activation.data[sample * layer->n_neurons + neuron] += layer->biases[neuron];
        }
    }

    // Create post-activation output matrix
    Matrix post_activation = create_matrix(pre_activation.rows, pre_activation.cols);

    // Apply activation function (ReLU or sigmoid)
    for (size_t sample = 0; sample < pre_activation.rows; sample++)
    {
        for (size_t neuron = 0; neuron < layer->n_neurons; neuron++)
        {
            if (is_output_layer)
            {
                post_activation.data[sample * layer->n_neurons + neuron] = sigmoid(pre_activation.data[sample * layer->n_neurons + neuron]);
            }
            else
            {
                post_activation.data[sample * layer->n_neurons + neuron] = relu(pre_activation.data[sample * layer->n_neurons + neuron]);
            }
        }
    }

    // Free pre_activation memory (since we don't need it anymore)
    free(pre_activation.data);

    // Store the output in the layer's output field
    layer->outputs = post_activation;

    return post_activation;
}

#endif