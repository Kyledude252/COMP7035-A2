#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H
#include <stdint.h>

typedef int32_t fixed_point_t;

//number of decimal point bits
#define FP_SHIFT 14
//1 in fixed point
#define FP_LIMIT (1 << FP_SHIFT)

//convert int into fixed point
fixed_point_t int_to_fp(int n){
    return n * FP_LIMIT;
}

//convert fixed point into int, rounding to 0
fixed_point_t fp_to_int_round_down(fixed_point_t a){
    return a / FP_LIMIT;
}

//convert fixed point to int, round to nearest int
fixed_point_t fp_to_int_round_nearest(fixed_point_t a){
    if(a >= 0){
        return (a - (FP_LIMIT / 2)) / FP_LIMIT;
    }
    else{
        return (a - (FP_LIMIT / 2))/ FP_LIMIT;
    }
}

//add fixed point numbers
fixed_point_t fp_add(fixed_point_t a, fixed_point_t b){
    return a + b;
}

//subtract fixed point numbers
fixed_point_t fp_subtract(fixed_point_t a, fixed_point_t b){
    return a - b;
}

//multiply fixed point numbers
fixed_point_t fp_multiply(fixed_point_t a, fixed_point_t b){
    return (((int64_t)a) * b) / FP_LIMIT;
}

//divide fixed point numbers
fixed_point_t fp_divide(fixed_point_t a, fixed_point_t b){
    return (((int64_t)a) * FP_LIMIT) / b;
}

#endif