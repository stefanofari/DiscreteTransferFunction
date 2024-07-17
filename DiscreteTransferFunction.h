#ifndef DISCRETE_TRANSFER_FUNCTION_H
#define DISCRETE_TRANSFER_FUNCTION_H

#include <Arduino.h>

struct DTFilterParams {
    const float* b;          // Feedforward coefficients
    const float* a;          // Feedback coefficients
    float* input_prev;       // Previous input samples
    float* output_prev;      // Previous output samples
    size_t b_size;           // Number of b coefficients
    size_t a_size;           // Number of a coefficients
};

class DiscreteTransferFunction {
public:
    static float apply(const DTFilterParams& params, float input);
};

#endif // DISCRETE_TRANSFER_FUNCTION_H
