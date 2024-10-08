#ifndef FORWARD_PROP_C
#define FORWARD_PROP_C

#include <stdio.h>

#include "../include/forward_prop.h"

Matrix forward_prop(Layer **layers, size_t n_layers, Matrix input_data)
{
    
    // Pass data through each layer
    Matrix current_output = input_data;

    for (size_t i = 0; i < n_layers; i++) {
        int is_output_layer = (i == n_layers - 1);

        // printf("%d\n", layers[i]->weights.rows);

        // Perform forward pass for the current layer
        current_output = forward_layer(*layers + i, current_output, is_output_layer);
    }

    return current_output;
}

#endif