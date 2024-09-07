#ifndef SCALING_H
#define SCALING_H

#include <stdlib.h>

/**
 * @brief Scales the specified columns of the feature matrix to a range [0, 1].
 *
 * This function performs Min-Max scaling on the specified columns of the feature matrix.
 * Each value in the specified columns is scaled to a range [0, 1] based on the minimum
 * and maximum values in that column.
 *
 * @param features A 2D array of doubles representing the feature matrix.
 * @param n_samples The number of samples (rows) in the feature matrix.
 * @param scale_columns An array of column indices that need to be scaled.
 * @param n_scale_columns The number of columns to be scaled.
 */
void min_max_scale(double **features, size_t n_samples, const size_t *scale_columns, size_t n_scale_columns); // Also knows as MinMaxScaler in sklearn in python

/**
 * @brief Scales the specified columns of the feature matrix to have zero mean and unit variance.
 *
 * This function performs Z-score scaling (standardization) on the specified columns of the feature matrix.
 * Each value in the specified columns is scaled to have a mean of 0 and a standard deviation of 1.
 *
 * @param features A 2D array of doubles representing the feature matrix.
 * @param n_samples The number of samples (rows) in the feature matrix.
 * @param scale_columns An array of column indices that need to be scaled.
 * @param n_scale_columns The number of columns to be scaled.
 */
void z_score_scale(double **features, size_t n_samples, const size_t *scale_columns, size_t n_scale_columns); // Also knows as StandartScaler in sklearn in python

#endif