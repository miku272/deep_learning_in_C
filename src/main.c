#include <stdio.h>
#include <stdlib.h>

#include "csv_handler.c"

int main()
{
    double **features;
    double *labels;
    size_t num_samples;
    size_t num_features;

    if (load_csv("../data/Churn_Modelling.csv", &features, &labels, &num_samples, &num_features) == 0)
    {
        print_loaded_csv(features, labels, num_samples, num_features);
    }

    for (size_t i = 0; i < num_samples; i++)
    {
        free(features[i]);
    }
    free(features);
    free(labels);

    return 0;
}
