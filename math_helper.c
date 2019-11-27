#include "math_helper.h"

T_F16 clamp(T_F16 val, T_F16 min, T_F16 max){
    if(val > max){
        return max;
    }
    if(val < min){
        return min;
    }
    return val;
}

