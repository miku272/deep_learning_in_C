#include <stdio.h>
#include <stdlib.h>

// #include "csv_handler.h"
// #include "scaling.h"

#include "matrix.c"
#include "csv_handler.c"
#include "scaling.c"
#include "layer.c"
#include "forward_prop.c"

int main()
{
    double **features;
    double *labels;
    size_t num_samples;
    size_t num_features;

    const size_t scale_cols[] = {0, 4, 6, 10}; // 0 = CreditScore, 4 = Age, 6 = Balance, 10 = EstimatedSalary
    const size_t n_scale_cols = sizeof(scale_cols) / sizeof(scale_cols[0]);

    if (load_csv("../data/Churn_Modelling.csv", &features, &labels, &num_samples, &num_features) == 0)
    {
        z_score_scale(features, num_samples, scale_cols, n_scale_cols);
        // print_loaded_csv(features, labels, num_samples, num_features, 5);

        const size_t n_layers = 3; // Input, Hidden, Output
        Layer *layers = (Layer *)malloc(n_layers * sizeof(Layer));

        layers[0] = create_layer(num_features, 11); // Input layer
        layers[1] = create_layer(11, 6);            // Hidden layer
        layers[2] = create_layer(6, 1);             // Output layer

        Matrix input_data = create_matrix(num_samples, num_features);
        for (size_t i = 0; i < num_samples; i++)
        {
            for (size_t j = 0; j < num_features; j++)
            {
                input_data.data[i * num_features + j] = features[i][j];
            }
        }

        Matrix output_data  = create_matrix(num_samples, 1);

        Matrix output = forward_prop(&layers, n_layers, input_data);
    }

    free_csv_data(features, labels, num_samples);

    return 0;
}
