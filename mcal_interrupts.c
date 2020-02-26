
#include "mcal_interrupts.h"

/* Interrupt Polarity */
#define NEG_EDGE 1
#define POS_EDGE 0

/* RF Interrupt Request Flag, set in INT2 by the nRF24L01 module*/
extern BOOL bRF_IRQ;


/* Obstacle sensor interrupt */
/*****************************/
void __attribute__((__interrupt__, no_auto_psv)) _INT0Interrupt(void)
{
    /* Write the code to detect obstacle */
    
    /* Clear INT0 flag */
    IFS0bits.INT0IF = 0;
    
    /* 
     * Set the global obstacle flag to the value of the current edge
     * 1 for negative edge
     */
    _vSetObstacleFlag(INTCON2bits.INT0EP);
    
    /* Flip the edge of interrupt */
    INTCON2bits.INT0EP ^= 1;
}


void __attribute__((__interrupt__, no_auto_psv)) _INT1Interrupt(void)
{
    /* Clear INT1 interrupt flag */
    IFS1bits.INT1IF = 0;
    
    /***************/
    /* Code below */
    /*************/
    
}


void __attribute__((__interrupt__, no_auto_psv)) _INT2Interrupt(void)
{
    /* Clear INT2 interrupt flag */
    IFS1bits.INT2IF = 0;
    
    /* Set nRF IRQ flag */
    bRF_IRQ = TRUE;
}


/*******************************************************************************
*  Function name    : INT_vInit
*  Description      : 1)Disables Nested Interrupts
*                     2)Enables the needed interrupt sources  
*                     3)Sets interrupt priority                
*  List of arguments: no arguments 
*  Return value     : no return value
********************************************************************************/
void INT_vInit()
{
    /* Disable Nested Interrupts */
    INTCON1bits.NSTDIS = 1;
    
    /* Call Interrupt Initialization Functions */
    
    /* INT0 - level 7 priority, RB7 */
    INT0_vInit(7);
    /* INT1 - level 6 priority, assigned to RP23 */
    INT1_vInit(6);
    /* INT2 - level 5 priority, tied to GND(not active) */
    INT2_vInit(5);
}


/*******************************************************************************
*  Function name    : INT0_vInit
*  Description      : 1)Sets INT0 interrupt priority
*                     2)Clears INT0 interrupt flag
*                     3)Enables INT0 interrupt                
*  List of arguments: T_U8 -interrupt priority: 7-> Highest
*                                               1-> Lowest
*                                               0-> Disabled   
*  Return value     : no return value
********************************************************************************/
void INT0_vInit(T_U8 u8Priority)
{
    /* Set INT0 priority */
    IPC0bits.INT0IP = u8Priority;
    /* Clear INT0 interrupt Flag */
    IFS0bits.INT0IF = 0;
    /* Interrupt on Neg. Edge */
    INTCON2bits.INT0EP = NEG_EDGE;
    /* INT0 Enable */
    IEC0bits.INT0IE = 1;
}


/*******************************************************************************
*  Function name    : INT1_vInit
*  Description      : 1)Sets INT1 interrupt priority
*                     2)Clears INT1 interrupt flag
*                     3)Enables INT1 interrupt
*                     4)Assign INT1 to RPx                
*  List of arguments: T_U8 -interrupt priority: 7-> Highest
*                                               1-> Lowest
*                                               0-> Disabled   
*  Return value     : no return value
********************************************************************************/
void INT1_vInit(T_U8 u8Priority)
{
    /* Set Remappable Pin RPx as INT1 source */
    RPINR0bits.INT1R = INT1Pin;
    /* Set INT1 priority */
    IPC5bits.INT1IP = u8Priority;
    /* Clear INT1 interrupt Flag */
    IFS1bits.INT1IF = 0;
    /* INT1 Enable */
    IEC1bits.INT1IE = 1;
}


/*******************************************************************************
*  Function name    : INT2_vInit
*  Description      : 1)Sets INT2 interrupt priority
*                     2)Clears INT2 interrupt flag
*                     3)Enables INT2 interrupt                
*  List of arguments: T_U8 -interrupt priority: 7-> Highest
*                                               1-> Lowest
*                                               0-> Disabled      
*  Return value     : no return value 
********************************************************************************/
void INT2_vInit(T_U8 u8Priority)
{
    /* Set Remappable Pin RPx as INT2 source */
    RPINR1bits.INT2R = INT2Pin;
    /* Set INT2 priority */
    IPC7bits.INT2IP = u8Priority;
    /* Clear INT2 interrupt Flag */
    IFS1bits.INT2IF = 0;
    /* INT2 Enable */
    IEC1bits.INT2IE = 1;
    /* Interrupt on Neg. Edge */
    INTCON2bits.INT2EP = NEG_EDGE;
}




