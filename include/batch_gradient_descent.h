#ifndef BATCH_GRADIENT_DESCENT_H
#define BATCH_GRADIENT_DESCENT_H

#include <stdlib.h>

/**
 * @brief Performs batch gradient descent to update weights and biases.
 *
 * @param weights A 2D array of weights to be updated.
 * @param biases A 1D array of biases to be updated.
 * @param dw A 2D array of weight gradients.
 * @param db A 1D array of bias gradients.
 * @param n_features The number of features in the dataset.
 * @param n_neurons The number of neurons in the layer.
 * @param learning_rate The learning rate for gradient descent.
 */
void batch_gradient_descent(double **weights, double *biases, double **dw, double *db, size_t n_features, size_t n_neurons, double learning_rate);

#endif