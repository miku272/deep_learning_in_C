/**
 * @file ann.h
 * @brief Header file for the neural network implementation.
 * 
 * This file contains and implements the core functionality of artificial neural
 * networks, and helper functions.
 */

#ifndef ANN_H
#define ANN_H

#include "matrix.h"

/**
 * @brief Represents a layer in a neural network.
 */
typedef struct Layer {
    size_t n_inputs;
    size_t n_neurons;
    Matrix weights;
    double *biases;
} Layer;

/**
 * @brief Creates a new layer with the specified number of inputs and neurons.
 *
 * @param n_inputs Number of inputs to the layer.
 * @param n_neurons Number of neurons in the layer.
 * @return Pointer to the newly created Layer.
 */
Layer* create_layer(size_t n_inputs, size_t n_neurons);

/**
 * @brief Frees the memory allocated for the layer.
 *
 * @param layer Pointer to the Layer to be freed.
 */
void free_layer(Layer *layer);

/**
 * @brief Performs a forward pass through the layer.
 *
 * @param layer Pointer to the Layer.
 * @param input 2D array of input values.
 * @param output 2D array to store the output values.
 * @param n_samples Number of input samples.
 */
void forward_layer(Layer *layer, double **input, double **output, size_t n_samples);

#endif