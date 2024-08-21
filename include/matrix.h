/**
 * @file matrix.h
 * @brief Header file containing functions for matrix operations.
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

/**
 * @struct Matrix
 * @brief Structure representing a matrix.
 * @var Matrix::rows
 * Number of rows in the matrix.
 * @var Matrix::cols
 * Number of columns in the matrix.
 * @var Matrix::data
 * Pointer to the data array of the matrix.
 */
typedef struct
{
    size_t rows;
    size_t cols;
    double *data;
} Matrix;

/**
 * @brief Creates a new matrix with the specified number of rows and columns.
 *
 * @param rows The number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 * @return The created matrix.
 */
Matrix create_matrix(size_t rows, size_t cols);

/**
 * @brief Adds two matrices element-wise.
 *
 * @param matrix1 Pointer to the first matrix.
 * @param matrix2 Pointer to the second matrix.
 * @return The resulting matrix after addition.
 */
Matrix matrix_add(const Matrix *matrix1, const Matrix *matrix2);

/**
 * @brief Multiplies a matrix by a scalar value.
 *
 * @param matrix Pointer to the matrix.
 * @param scalar The scalar value to multiply the matrix by.
 * @return The resulting matrix after scalar multiplication.
 */
Matrix scalar_multiply(const Matrix *matrix, double scalar);

/**
 * @brief Multiplies two matrices.
 *
 * @param matrix1 Pointer to the first matrix.
 * @param matrix2 Pointer to the second matrix.
 * @return The resulting matrix after matrix multiplication.
 */
Matrix matrix_multiply(const Matrix *matrix1, const Matrix *matrix2);

/**
 * @brief Prints the elements of a matrix.
 *
 * @param matrix Pointer to the matrix to be printed.
 */
void print_matrix(const Matrix *matrix);

/**
 * @brief Frees the memory allocated for a matrix.
 *
 * @param matrix Pointer to the matrix to be freed.
 */
void free_matrix(Matrix *matrix);

#endif