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
        print_loaded_csv(features, labels, num_samples, num_features, 5);
    }

    free_csv_data(features, labels, num_samples);

    return 0;
}
