#include <stdio.h>
#include <stdlib.h>

#include "../include/matrix.h"

Matrix create_matrix(size_t rows, size_t cols)
{
    Matrix matrix;

    matrix.rows = rows;
    matrix.cols = cols;

    matrix.data = (double *)malloc(rows * cols * sizeof(double));

    return matrix;
}

Matrix matrix_add(const Matrix *matrix1, const Matrix *matrix2)
{
    Matrix result = create_matrix(matrix1->rows, matrix1->cols);

    for (size_t i = 0; i < matrix1->rows; i++)
    {
        for (size_t j = 0; j < matrix1->cols; j++)
        {
            result.data[i * matrix1->cols + j] = matrix1->data[i * matrix1->cols + j] + matrix2->data[i * matrix1->cols + j];
        }
    }

    return result;
}

Matrix scalar_multiply(const Matrix *matrix, double scalar)
{
    Matrix result = create_matrix(matrix->rows, matrix->cols);

    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->cols; j++)
        {
            result.data[i * matrix->cols + j] = matrix->data[i * matrix->cols + j] * scalar;
        }
    }

    return result;
}

Matrix matrix_multiply(const Matrix *matrix1, const Matrix *matrix2)
{
    Matrix result = create_matrix(matrix1->rows, matrix2->cols);

    for (size_t i = 0; i < matrix1->rows; i++)
    {
        for (size_t j = 0; j < matrix2->cols; j++)
        {
            result.data[i * matrix2->cols + j] = 0;

            for (size_t k = 0; k < matrix1->cols; k++)
            {
                result.data[i * matrix2->cols + j] += matrix1->data[i * matrix1->cols + k] * matrix2->data[k * matrix2->cols + j];
            }
        }
    }

    return result;
}

void print_matrix(const Matrix *matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->cols; j++)
        {
            printf("%f ", matrix->data[i * matrix->cols + j]);
        }

        printf("\n");
    }
}

void free_matrix(Matrix *matrix)
{
    if (matrix->data != NULL)
    {
        free(matrix->data);
        matrix->data = NULL;
    }
}