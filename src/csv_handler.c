#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/csv_handler.h"

#define MAX_LINE_LENGTH 1024

int load_csv(const char *filename, double ***features, double **labels, size_t *n_samples, size_t *n_features)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    size_t row_count = 0;
    size_t col_count = 0;

    // First pass: Determine number of rows and columns
    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        if (row_count == 0)
        {
            // Count columns in the header
            char *token = strtok(line, ",");
            while (token)
            {
                col_count++;
                token = strtok(NULL, ",");
            }
        }
        row_count++;
    }

    *n_samples = row_count - 1; // Exclude header row

    // Account for one-hot encoding:  3 unique countries in Geography (France, Spain, Germany)
    *n_features = col_count - 4 + 2 - 1; // Exclude RowNumber, CustomerId, Surname, geography; add 2 for Geography(One hot encoding), subtract 1 for Exited (label)

    // Allocate memory for features and labels
    *features = (double **)malloc(*n_samples * sizeof(double *));
    *labels = (double *)malloc(*n_samples * sizeof(double));
    for (size_t i = 0; i < *n_samples; i++)
    {
        (*features)[i] = (double *)malloc(*n_features * sizeof(double));
    }

    // Reset file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    // Second pass: Read the data
    row_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        if (row_count == 0)
        {
            row_count++; // Skip the header
            continue;
        }

        char *token = strtok(line, ",");
        size_t col_index = 0;
        size_t feature_index = 0;

        while (token)
        {
            if (col_index == 13)
            { // Exited (Label)
                (*labels)[row_count - 1] = atof(token);
            }
            else if (col_index == 4)
            { // Geography (One-Hot Encoding)
                if (strcmp(token, "France") == 0)
                {
                    (*features)[row_count - 1][feature_index++] = 1.0;
                    (*features)[row_count - 1][feature_index++] = 0.0;
                }
                else if (strcmp(token, "Spain") == 0)
                {
                    (*features)[row_count - 1][feature_index++] = 0.0;
                    (*features)[row_count - 1][feature_index++] = 1.0;
                }
                else if (strcmp(token, "Germany") == 0)
                {
                    (*features)[row_count - 1][feature_index++] = 0.0;
                    (*features)[row_count - 1][feature_index++] = 0.0;
                }
            }
            else if (col_index == 5)
            { // Gender (Label Encoding)
                (*features)[row_count - 1][feature_index++] = (strcmp(token, "Male") == 0) ? 0.0 : 1.0;
            }
            else if (col_index > 2 && col_index < 13)
            { // Process other features
                if (col_index != 4 && col_index != 5)
                { // Skip Geography and Gender as they're handled separately
                    (*features)[row_count - 1][feature_index++] = atof(token);
                }
            }
            token = strtok(NULL, ",");
            col_index++;
        }
        row_count++;
    }

    fclose(file);
    return 0;
}

void print_loaded_csv(double **features, double *labels, size_t num_samples, size_t num_features, size_t limit)
{
    size_t samples = 0;

    if (limit < 0)
    {
        printf("Please enter valid sample limit");
        return;
    }
    else if (limit > num_samples)
    {
        printf("Sample limit size exceeds total samples");
        return;
    }
    else
    {
        samples = limit;
    }

    printf("Sample #\tFeatures\t\t\t\tLabel\n");
    printf("------------------------------------------------------------\n");

    for (size_t i = 0; i < samples; i++)
    {
        printf("%zu\t\t", i + 1);

        // Print features
        for (size_t j = 0; j < num_features; j++)
        {
            printf("%.2f ", features[i][j]);
        }

        // Print corresponding label
        printf("\t%.2f\n", labels[i]);
    }
}

void free_csv_data(double **features, double *labels, size_t n_samples)
{
    for (size_t i = 0; i < n_samples; i++)
    {
        free(features[i]);
    }
    free(features);

    free(labels);
}