#include "light_sig.h"
#include "general.h"

void light_obstacle(){
    
    static T_U16 time = 0;
    
    if(time < 25){
        GPIO_u8WritePortPin(PORT_A, 10, 1);
        ++time;
    }else if(time < 100){
        GPIO_u8WritePortPin(PORT_A, 10, 0);
        ++time;
    }else{
        time = 0;
    }
}

void light_battery_low(){
    
    static T_U16 time = 0;
    
    if(time < 100){
        GPIO_u8WritePortPin(PORT_A, 10, 1 - (time/20)%2);
        ++time;
    }else if(time < 200){
        GPIO_u8WritePortPin(PORT_A, 10, 0);
        ++time;
    }else{
        time = 0;
    }
}
