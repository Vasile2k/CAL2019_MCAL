#include "hal_encoder.h"
#include "mcal_encoder.h"

#define WHEEL_RADIUS 2
#define PI 3.14159265359
#define WHEEL_CIRCUMFERENCE (2 * PI * WHEEL_RADIUS) 
#define GEAR_RATIO 100
#define PULSES_PER_ROTATION_PER_CHANNEL 6
#define NUMBER_OF_CHANNELS 2


extern T_F16 HAL_f16GetElapsedDistance(void){
    T_S16 pulses = QEI_s16getElapsed();
    return (T_F16)pulses/(PULSES_PER_ROTATION_PER_CHANNEL * NUMBER_OF_CHANNELS * GEAR_RATIO) * WHEEL_CIRCUMFERENCE;
}
