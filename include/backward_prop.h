#ifndef backward_prop_H
#define backward_prop_H

#include "layer.h"

/**
 * @brief Performs the backward propagation algorithm for a neural network.
 *
 * This function updates the weights and biases of the neural network layers
 * based on the error between the predicted output and the target output.
 *
 * @param layers Pointer to an array of Layer pointers representing the layers of the neural network.
 * @param n_layers The number of layers in the neural network.
 * @param inputs Pointer to a 2D array containing the input data for the neural network.
 * @param targets Pointer to a 2D array containing the target output data for the neural network.
 * @param n_samples The number of samples in the input data.
 * @param learning_rate The learning rate used for updating the weights and biases.
 */
void backward_prop(Layer **layers, size_t n_layers, double **inputs, double **targets, size_t n_samples, double learning_rate);

#endif