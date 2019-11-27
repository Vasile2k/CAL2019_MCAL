#include "hal_servo.h"
#include "mcal_pwm.h"
#include "math_helper.h"

void HAL_vServoInit(void){
    PWM1_vInit();
}

void HAL_vServoSetPosition(T_F16 position){
    // Translate from [50; 130] to duty cycle between [4, 11]
    T_F16 duty = 7.5 + ((position - 90)/80) * 3.5;
    // Make sure value is not out of range
    duty = clamp(duty, (T_F16)6.15, (T_F16)8.81);
    // And set PWM
    PWM1_vSetDuty(duty, 1);
}
