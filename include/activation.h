/**
 * @file activation.h
 * @brief Header file containing functions for activations.
 */

#ifndef ACTIVATION_H
#define ACTIVATION_H

/**
 * @brief Calculates the sigmoid function for a given input.
 *
 * @param x The input value.
 * @return The result of the sigmoid function for the given input.
 */
double sigmoid(double x);

/**
 * @brief Calculates the derivative of the sigmoid function for a given input.
 *
 * @param x The input value.
 * @return The derivative of the sigmoid function for the given input.
 */
double sigmoid_derivative(double x);

/**
 * @brief Calculates the ReLU (Rectified Linear Unit) function for a given input.
 *
 * @param x The input value.
 * @return The result of the ReLU function for the given input.
 */
double relu(double x);

/**
 * @brief Calculates the derivative of the ReLU function for a given input.
 *
 * @param x The input value.
 * @return The derivative of the ReLU function for the given input.
 */
double relu_derivative(double x);

#endif