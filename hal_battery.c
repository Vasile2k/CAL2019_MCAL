#include "hal_battery.h"
#include "mcal_adc.h"

/**
 * The ADC channel where the battery feedback is connected
 */
#define ADC_BATTERY_CHANNEL 0

/**
 * The amount of samples from ADC to apply a median filter on
 * for more accurate results
 */
#define MEDIAN_SAMPLES 5

/**
 * Analog reference voltage
 */
#define AREF_VOLTAGE 3.07

typedef struct{
    T_F16 voltage;
    T_F16 charge;
} lutType;

lutType batteryLookupTable[] = {
    {8.4, 1.0},
    {7.0, 0.2},
    {6.5, 0.1},
    {6.0, 0.0}
};

T_F16 HAL_f16ReadBatteryPercentage(){
    T_U16 samples[MEDIAN_SAMPLES];
    T_U16 result;
    T_U16 i;
    for(i = 0; i < MEDIAN_SAMPLES; ++i){
        samples[i] = ADC_u16Read(ADC_BATTERY_CHANNEL);
    }
    
    long long sum = 0;
    for(i = 0; i < MEDIAN_SAMPLES; ++i){
        sum += samples[i];
    }
    result = sum/MEDIAN_SAMPLES;
    
    // Shorter name
    lutType* lut = batteryLookupTable;
    
    // Battery is read via a resistive voltage divider with a 1/4 ratio
    T_F16 battVoltage = 4*(result*AREF_VOLTAGE/0x0FFF);
    for(i = 0; i < (sizeof(batteryLookupTable)/sizeof(batteryLookupTable[0]) - 1); ++i){
        if(battVoltage < lut[i + 1].voltage){
            continue;
        }
        T_F16 percent = (lut[i].charge - lut[i+1].charge)*(battVoltage - lut[i+1].voltage)/(lut[i].voltage - lut[i+1].voltage) + lut[i+1].charge;
        return percent;
    }
    return 0.0;
}
