/**
 * @file kalman.h
 * @author Denis Shreiber (chuyecd@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _KALMAN_H_
#define _KALMAN_H_

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Struct to store filter state
 */
typedef struct {
    float k;                //!< Kalman filter coefficient (0 <= k <= 1)
    union {
        float val_f;        //!< Last filter value as float
        int32_t val_i32;    //!< Last filter value as i32
        uint32_t val_u32;   //!< Last filter value as u32
    };
} kalman_filter_t;

/**
 * @brief Filter one value using Kalman filter
 * 
 * @param filter    Filter structure
 * @param new_val   New value to filter
 * @return New filterred value
 */
float kalman_f(kalman_filter_t *filter, float new_val);

/**
 * @brief Filter array using Kalman filter
 * 
 * @param filter    Filter structure
 * @param in[in]    Input aray to filter
 * @param out[out]  Output filterred data
 * @param length Size of data to filter
 */
void kalman_array_f(kalman_filter_t *filter, float *in, float *out, size_t length);

#endif // _KALMAN_H_