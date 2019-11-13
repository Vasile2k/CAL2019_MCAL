#include "light_sig.h"
#include "general.h"

T_U16 l_o = 0;
T_U16 l_b = 0;

void light_obstacle(){
    if(l_o < 25){
        GPIO_u8WritePortPin(PORT_A, 10, 1);
        ++l_o;
    }else if(l_o < 100){
        GPIO_u8WritePortPin(PORT_A, 10, 0);
        ++l_o;
    }else{
        l_o = 0;
    }
}

void light_battery_low(){
    if(l_b < 100){
        GPIO_u8WritePortPin(PORT_A, 10, 1 - (l_b/20)%2);
        ++l_b;
    }else if(l_b < 200){
        GPIO_u8WritePortPin(PORT_A, 10, 0);
        ++l_b;
    }else{
        l_b = 0;
    }
}
