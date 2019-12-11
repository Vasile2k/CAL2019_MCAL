#include "hal_lf.h"

void HAL_vSetLineFollower(BOOL direction){
    T_U8 pin;
    for(pin = 0; pin < 6; ++pin){
        GPIO_u8SetPortPin(PORT_C, pin, DIGITAL, direction);
    }
}

void HAL_vWriteLineFollower(BOOL value){
    // Read initial value
    T_U16 port = GPIO_u16ReadPort(PORT_C);
    // Change only what we need
    if(value){
        port |= 0x3F;
    }else{
        port &= (~0x3F);
    }
    // Write it back
    GPIO_vWritePort(PORT_C, port);
}

T_U8 HAL_vGetLineFollower(){
    // Power the LF module
    HAL_vSetLineFollower(OUTPUT);
    HAL_vWriteLineFollower(1);
    // Wait for 10 us
    __delay_us(10);
    // Set it as input and wait one more ms
    HAL_vSetLineFollower(INPUT);
    __delay_ms(1);
    
    // Read port and keep only last 5 bits
    T_U8 result = (T_U8)GPIO_u16ReadPort(PORT_C) & 0x3F;
    
    return result;
}
