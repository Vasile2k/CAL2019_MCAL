#include "hal_lf.h"
#include "mcal_gpio.h"

void HAL_vSetLineFollower(T_U8 direction){
    T_U8 pin;
    for(pin = 0; pin < 6; ++pin){
        GPIO_u8SetPortPin(PORT_C, 0, DIGITAL, direction);
    }
}

void HAL_vWriteLineFollower(BOOL value){
    // Read initial value
    T_U16 port = GPIO_u16ReadPort(PORT_C);
    // Change only what we need
    if(value){
        port |= 0x1F;
    }else{
        port &= (~0x1F);
    }
    // Write it back
    GPIO_vWritePort(PORT_C, port);
}

T_U8 HALvGetLineFollower(){
    // Read port and keep only last 5 bits
    T_U8 result = (T_U8)GPIO_u16ReadPort(PORT_C) & 0x1F;
    return result;
}
