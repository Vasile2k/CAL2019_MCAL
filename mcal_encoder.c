#include "mcal_encoder.h"

/*******************************************************************************
*  Function name    : Encoder_vInit
*  Description      : 1)Initializes the QEI(Quadrature Encoder Interface)
*                     2)Sets the count register value in the middle for easier 
*                       data processing(by decreasing count reset probability)          
*  List of arguments: no arguments
*  Return value     : no return value
********************************************************************************/
void QEI_vInit(void)
{
    /* Set channel A and B microcontroller pins as Inputs */
    TRISCbits.TRISC9 = 1;
    TRISBbits.TRISB15 = 1;
    
    /* Assign channel A to RP15 */
    RPINR14bits.QEA1R = 15;
    /* Assign channel B to RP25 */
    RPINR14bits.QEB1R = 25;
    
    /* Timer Input Clock Prescale 1:64 */
    QEI1CONbits.TQCKPS = 0b10;           
    /* Encoder enabled (x4 mode) with position counter reset by match(MAXxCNT) */
    QEICONbits.QEIM = 0b111; 
    /* Set count register value around the middle of the possible value range */
    POS1CNT = RESET_VALUE;
    /* Count value can be read from POS1CNT register */
}

/*******************************************************************************
*  Function name    : Encoder_u16getCount
*  Description      : Returns POS1CNT(count register) value        
*  List of arguments: no arguments
*  Return value     : T_U16 -> value of POS1CNT.
*                     POS1CNT is initialized at RESET_VALUE
*                     POS1CNT is: incremented when moving backwards
*                                 decremented when moving forward 
********************************************************************************/
T_U16 QEI_u16getCount()
{
    return POS1CNT;
}


/*******************************************************************************
*  Function name    : QEI_vResetCount
*  Description      : Resets the count register to RESET_VALUE         
*  List of arguments: no arguments
*  Return value     : no return value  
********************************************************************************/
void QEI_vResetCount()
{
    POS1CNT = RESET_VALUE;
}

/*******************************************************************************
*  Function name    : QEI_s16getElapsed
*  Description      : Returns the elapsed distance since last call
*  List of arguments: no arguments
*  Return value     : no return value  the elapsed distance since last call
********************************************************************************/
T_S16 QEI_s16getElapsed(void){
    T_S16 elapsed = QEI_u16getCount() - RESET_VALUE;
    QEI_vResetCount();
    return elapsed;
}
