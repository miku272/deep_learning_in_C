/**
 * @file ann.h
 * @brief Header file for the neural network implementation.
 *
 * This file contains and implements the core functionality of layers for artificial neural
 * networks, and helper functions.
 */

#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"

/**
 * @brief Represents a layer in a neural network.
 */
typedef struct Layer
{
    size_t n_inputs;
    size_t n_neurons;
    Matrix weights;
    double *biases;
    Matrix outputs;
} Layer;

/**
 * @brief Creates a new layer with the specified number of inputs and neurons.
 *
 * @param n_inputs Number of inputs to the layer.
 * @param n_neurons Number of neurons in the layer.
 * @return Pointer to the newly created Layer.
 */
Layer *create_layer(size_t n_inputs, size_t n_neurons);

/**
 * @brief Frees the memory allocated for the layer.
 *
 * @param layer Pointer to the Layer to be freed.
 */
void free_layer(Layer *layer);

/**
 * @brief Performs a forward pass through the layer.
 *
 * This function takes the input data and processes it through the layer to produce the output.
 * The input data is a 2D array where each row represents a sample and each column represents a feature.
 * The output data is also a 2D array where each row represents a sample and each column represents the output from a neuron.
 *
 * @param layer Pointer to the Layer.
 * @param input_data 2D array of input values.
 * @param is_output_layer integer variable indicating whether the given layer is output layer or not
 * @return Matrix 2D array containing the output values.
 */
Matrix forward_layer(Layer *layer, Matrix input_data, int is_output_layer);

#endif