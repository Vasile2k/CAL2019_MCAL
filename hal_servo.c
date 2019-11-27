#include "hal_servo.h"
#include "mcal_pwm.h"
#include "math_helper.h"

void HAL_vServoInit(void){
    PWM1_vInit();
}

void HAL_vServoSetPosition(T_F16 position){
    // Translate from [10; 170] to duty cycle between [4, 11]
    T_F16 duty = 7.5 + (position - 10)/160 * 3.5;
    // Make sure values is not out of range
    duty = clamp(duty, 4, 11);
    // And set PWM
    PWM1_vSetDuty(duty, 1);
}
