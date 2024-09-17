#include <stdlib.h>

#include "../include/forward_prop.h"

#include "./activation.c"
#include "./matrix.c"

void forward_prop(Layer **layers, size_t n_layers, double **input, size_t n_input, double **output, size_t n_samples)
{
    Matrix input_matrix = create_matrix(n_samples, layers[0]->n_inputs);
    for (size_t i = 0; i < n_samples; i++)
    {
        for (size_t j = 0; j < layers[0]->n_inputs; j++)
        {
            input_matrix.data[i * layers[0]->n_inputs + j] = input[i][j];
        }
    }

    Matrix current_input = input_matrix;
    Matrix current_output;

    for (size_t i = 0; i < n_layers; i++)
    {
        Layer *layer = layers[i];

        // Multiply input with weights
        current_output = matrix_multiply(&current_input, &layer->weights);

        // Apply biases and activation function
        for (size_t sample = 0; sample < n_samples; sample++)
        {
            for (size_t neuron = 0; neuron < layer->n_neurons; neuron++)
            {
                current_output.data[sample * layer->n_neurons + neuron] += layer->biases[neuron];

                // Apply activation function (ReLU for hidden layers, sigmoid for output layer)
                if (i < n_layers - 1)
                {
                    current_output.data[sample * layer->n_neurons + neuron] = relu(current_output.data[sample * layer->n_neurons + neuron]);
                }
                else
                {
                    current_output.data[sample * layer->n_neurons + neuron] = sigmoid(current_output.data[sample * layer->n_neurons + neuron]);
                }
            }
        }

        // Free input matrix if it is not the original input matrix
        if (i > 0)
        {
            free(current_input.data);
        }
        current_input = current_output; // Set current output as input for next layer
    }

    // Copy current_output to output
    for (size_t i = 0; i < n_samples; i++)
    {
        for (size_t j = 0; j < layers[n_layers - 1]->n_neurons; j++)
        {
            output[i][j] = current_output.data[i * layers[n_layers - 1]->n_neurons + j];
        }
    }

    // Free memory for the last output matrix
    free(current_output.data);
    free(input_matrix.data);
}