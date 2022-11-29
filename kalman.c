/**
 * @file kalman.c
 * @author Denis Shreiber (chuyecd@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "kalman.h"

int kalman_init_f(kalman_filter_t *filter, float k, float val) {
    if (filter->k > 1) {
        return -1;
    }
    else if (filter->k < 0) {
        return -1;
    }

    filter->k = k;
    filter->val_f = val;

    return 0;
}

float kalman_f(kalman_filter_t *filter, float new_val) {
    float new_filtered_val = filter->k * filter->val_f + (1 - filter->k) * new_val;

    filter->val_f = new_filtered_val;

    return new_filtered_val;
}

void kalman_array_f(kalman_filter_t *filter, float *in, float *out, size_t length) {
    for (int q = 0; q < length; q++) {
        out[q] = kalman_f(filter, in[q]);
    }
}
