/**
 * @file loss.h
 * @brief Header file for loss functions.
 *
 * This file contains the declarations of loss functions used in deep learning models.
 */

#ifndef LOSS_H
#define LOSS_H

/**
 * @brief Calculates the mean squared error between actual and expected values.
 *
 * This function calculates the mean squared error between the actual and expected values
 * for a given length of data.
 *
 * @param actual Pointer to the array of actual values.
 * @param predicted Pointer to the array of predicted values.
 * @param length The length of the arrays.
 * @return The mean squared error between the actual and expected values.
 */
double mean_squared_error(const double *actual, const double *predicted, size_t length);

/**
 * @brief Calculates the derivative of the mean squared error with respect to the predicted values.
 *
 * This function calculates the gradient of the mean squared error loss function with respect to the predicted values.
 * The gradient is useful for backpropagation in training deep learning models.
 *
 * @param actual Pointer to the array of actual values.
 * @param predicted Pointer to the array of predicted values.
 * @param gradient Pointer to the array where the calculated gradient will be stored.
 * @param length The length of the arrays.
 */
void mean_squared_error_derivative(const double *actual, const double *predicted, double *gradient, size_t length);

/**
 * @brief Calculates the cross-entropy loss between the actual and predicted values.
 *
 * This function computes the cross-entropy loss, which is commonly used in classification problems.
 * The cross-entropy loss measures the performance of a classification model whose output is a probability value between 0 and 1.
 *
 * @param actual Pointer to the array of actual values (ground truth).
 * @param predicted Pointer to the array of predicted values (model output probabilities).
 * @param length The length of the arrays.
 * @return The calculated cross-entropy loss.
 */
double cross_entropy_loss(const double *actual, const double *predicted, size_t length);

/**
 * @brief Calculates the derivative of the cross-entropy loss with respect to the predicted values.
 *
 * This function calculates the gradient of the cross-entropy loss function with respect to the predicted values.
 * The gradient is useful for backpropagation in training deep learning models.
 *
 * @param actual Pointer to the array of actual values (ground truth).
 * @param predicted Pointer to the array of predicted values (model output probabilities).
 * @param gradient Pointer to the array where the calculated gradient will be stored.
 * @param length The length of the arrays.
 */
void cross_entropy_loss_derivative(const double *actual, const double *predicted, double *gradient, size_t length);

#endif