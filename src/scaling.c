#include <float.h>
#include <math.h>

// #include "scaling.h"
#include "../include/scaling.h"

void min_max_scale(double **features, size_t n_samples, const size_t *scale_columns, size_t n_scale_columns)
{
    for (size_t idx = 0; idx < n_scale_columns; idx++)
    {
        size_t col = scale_columns[idx];
        double min_value = DBL_MAX;
        double max_value = DBL_MIN;

        // Find max and min for the specified feature column
        for (size_t i = 0; i < n_samples; i++)
        {
            if (features[i][col] < min_value)
            {
                min_value = features[i][col];
            }
            if (features[i][col] > max_value)
            {
                max_value = features[i][col];
            }
        }

        // Scale the feature column to [0, 1]
        for (size_t i = 0; i < n_samples; i++)
        {
            if (max_value > min_value)
            {
                features[i][col] = (features[i][col] - min_value) / (max_value - min_value);
            }
            else
            {
                features[i][col] = 0.0; // If max and min are equal, scale to 0
            }
        }
    }
}

void z_score_scale(double **features, size_t n_samples, const size_t *scale_columns, size_t n_scale_columns)
{
    for (size_t idx = 0; idx < n_scale_columns; idx++)
    {
        size_t col = scale_columns[idx];
        double mean = 0.0;
        double variance = 0.0;
        double std_dev = 0.0;

        // Calculate mean for the specified feature column
        for (size_t i = 0; i < n_samples; i++)
        {
            mean += features[i][col];
        }
        mean /= n_samples;

        // Calculate variance for the specified feature column
        for (size_t i = 0; i < n_samples; i++)
        {
            variance += pow(features[i][col] - mean, 2);
        }
        variance /= n_samples;

        // Calculate standard deviation for the specified feature column
        std_dev = sqrt(variance);

        // Scale the feature column to have zero mean and unit variance (standard deviation)
        for (size_t i = 0; i < n_samples; i++)
        {
            if (std_dev > 0.0)
            {
                features[i][col] = (features[i][col] - mean) / std_dev;
            }
            else
            {
                features[i][col] = 0.0; // If standard deviation is zero, scale to 0
            }
        }
    }
}