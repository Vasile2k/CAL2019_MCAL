#include "asw_lf.h"
#include "rte.h"

#define AVERAGE_WINDOW 4

void ASW_vfollowLine(){
    // Meadian filter on last N elements
    // Hope this shit works, otherwise I'm gonna cut my penis
    static T_F16 values[AVERAGE_WINDOW] = { [0 ... (AVERAGE_WINDOW - 1)] = 3.5 };
    static int pos = 0;
    
    RTE_vMotorSetDir(FORWARD);
    RTE_vMotorSetSpeed(90);
    T_U16 lf = RTE_vGetLineFollower();
    T_F16 dir = getDirectionFromLF(lf);
    // If we lose signal, keep last known position
    if(dir != -1){
        T_F16 position = (T_F16)3.5 - dir;
        pos++;
        pos %= AVERAGE_WINDOW;
        values[pos] = position;
        
        T_F16 mean = 0;
        int i = 0;
        for(i = 0; i < AVERAGE_WINDOW; ++i){
            mean += values[i];
        }
        mean /= AVERAGE_WINDOW;
        
        RTE_vServoSetPosition(90 + mean * 20.0);
    }
}

/***
 * Compute direction of wheels from a given input
 */
T_F16 getDirectionFromLF(T_U16 input){
    
    if(input == 0 || input == 0x3F){
        return -1;
    }
    
    union {
        struct{
            T_U8 byte;
        };
        struct{
            T_U8 b0 : 1;
            T_U8 b1 : 1;
            T_U8 b2 : 1;
            T_U8 b3 : 1;
            T_U8 b4 : 1;
            T_U8 b5 : 1;
        };
    } lp; // Line position
    lp.byte = (T_U8)input;

    T_U8 bitsOf1Count = lp.b0 + lp.b1 + lp.b2 + lp.b3 + lp.b4 + lp.b5;

    T_F16 weightedAverage = (T_F16)(lp.b0 * 1 + lp.b1 * 2 + lp.b2 * 3 + lp.b3 * 4 + lp.b4 * 5 + lp.b5 * 6)/bitsOf1Count;
    return weightedAverage;
}
