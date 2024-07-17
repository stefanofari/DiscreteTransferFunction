#include "DiscreteTransferFunction.h"

float DiscreteTransferFunction::apply(const DTFilterParams& params, float input) {
    float output = 0.0;

    // Shift the previous inputs and outputs for the new calculations
    for (size_t i = params.b_size - 1; i > 0; --i) {
        params.input_prev[i] = params.input_prev[i - 1];
    }
    params.input_prev[0] = input;

    // Compute output based on previous inputs and outputs
    for (size_t i = 0; i < params.b_size; ++i) {
        output += params.b[i] * params.input_prev[i];
    }

    for (size_t i = 1; i < params.a_size; ++i) {
        output -= params.a[i] * params.output_prev[i - 1];
    }
    params.output_prev[0] = output;

    return output;
}
