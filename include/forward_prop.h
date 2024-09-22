#ifndef FORWARD_PROP_H
#define FORWARD_PROP_H

#include "matrix.h"
#include "layer.h"

/**
 * @brief Performs forward propagation through the neural network layers.
 *
 * This function takes an array of layers and input data, and performs
 * forward propagation through each layer in the network. The result of
 * each layer's computation is passed as input to the next layer.
 *
 * @param layers An array of pointers to Layer structures representing the neural network layers.
 * @param n_layers The number of layers in the neural network.
 * @param input_data A Matrix structure containing the input data to the neural network.
 */
void forward_prop(Layer **layers, size_t n_layers, Matrix input_data);

#endif