#ifndef CSV_HANDLER_H
#define CSV_HANDLER_H

#include <stddef.h>

/**
 * @brief Loads data from a CSV file.
 *
 * This function reads a CSV file and loads the data into a 2D array for features and a 1D array for labels.
 *
 * @param filename The name of the CSV file to load.
 * @param features A pointer to a 2D array where the features will be stored. The memory will be allocated by this function.
 * @param labels A pointer to a 1D array where the labels will be stored. The memory will be allocated by this function.
 * @param n_samples A pointer to a size_t variable where the number of samples will be stored.
 * @param n_features A pointer to a size_t variable where the number of features will be stored.
 * @return int Returns 0 on success, or a non-zero error code on failure.
 */
int load_csv(const char *filename, double ***features, double **labels, size_t *n_samples, size_t *n_features);

/**
 * @brief Prints the loaded CSV data.
 *
 * This function prints the features and labels stored in the 2D array and 1D array respectively.
 *
 * @param features A 2D array containing the features to be printed.
 * @param labels A 1D array containing the labels to be printed.
 * @param num_samples The number of samples (rows) in the features array.
 * @param num_features The number of features (columns) in the features array.
 */
void print_loaded_csv(double **features, double *labels, size_t num_samples, size_t num_features);

/**
 * @brief Frees the memory allocated for CSV data.
 *
 * This function frees the memory allocated for the features and labels arrays.
 *
 * @param features The 2D array of features to be freed.
 * @param labels The 1D array of labels to be freed.
 * @param n_samples The number of samples (rows) in the features array.
 */
void free_csv_data(double **features, double *labels, size_t n_samples);

#endif