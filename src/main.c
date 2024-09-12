#include <stdio.h>
#include <stdlib.h>

// #include "csv_handler.h"
// #include "scaling.h"

#include "csv_handler.c"
#include "scaling.c"

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
        print_loaded_csv(features, labels, num_samples, num_features, 5);
    }

    free_csv_data(features, labels, num_samples);

    return 0;
}
