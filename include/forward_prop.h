#ifndef FORWARD_PROP_H
#define FORWARD_PROP_H

#include "ann.h";

/**
 * @brief Performs forward propagation through the neural network layers.
 *
 * This function takes the input data and propagates it through each layer of the neural network,
 * computing the output at each layer and ultimately producing the final output.
 *
 * @param layers A pointer to an array of Layer pointers representing the layers of the neural network.
 * @param n_layers The number of layers in the neural network.
 * @param input A pointer to a 2D array of doubles representing the input data.
 * @param n_input The number of input data points.
 * @param output A pointer to a 2D array of doubles where the output data will be stored.
 * @param n_output The number of output data points.
 */
void forward_prop(Layer **layers, size_t n_layers, double **input, size_t n_input, double **output, size_t n_output);

#endif