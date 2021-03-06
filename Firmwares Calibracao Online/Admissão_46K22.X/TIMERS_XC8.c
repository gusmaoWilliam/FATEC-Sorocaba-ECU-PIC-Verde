/*
 * File:   main.c
 * Author: Hiroki
 *
 * 
 * Timer�s_XC8
 */

#include "Config_XC8.h"
#include "TIMERS_XC8.h"
#include <stdlib.h>

/******************************************* 16 Bit�s Timer ******************************************/
void Config_Timer1( void )
{
    TMR1IE = 0;
/*************************************************
*T1CON PS                                         * 
*1 = 1:8 Prescale value                           *
*10 = 1:4 Prescale value                          *
*01 = 1:2 Prescale value                          *
*00 = 1:1 Prescale value                          *
**************************************************/
    T1CONbits.T1CKPS1 = 1;
    T1CONbits.T1CKPS0 = 0;
/*************************************************/
    T1CONbits.T1OSCEN = 0;
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1RD16 = 1;

    
    T1CONbits.TMR1ON = nENABLE;   
}

void Set_Timer1(unsigned int data_timer )
{
    TMR1H = data_timer >> 8;        
    TMR1L = data_timer & 0x00FF;    
}

unsigned int Get_Timer1()
{
    unsigned int Data;
    Data = TMR1H << 8 | TMR1L;
    return Data;
}
/*====================================================================================================*/

void Config_Timer3( void ) 
{
    TMR3IE = 0;
/*************************************************
*T1CON PS                                         * 
*1 = 1:8 Prescale value                           *
*10 = 1:4 Prescale value                          *
*01 = 1:2 Prescale value                          *
*00 = 1:1 Prescale value                          *
**************************************************/
    T3CONbits.T3CKPS1 = 0;
    T3CONbits.T3CKPS0 = 1;
/*************************************************/
    T3CONbits.T3OSCEN = 0;
    T3CONbits.TMR3CS = 0;
    T3CONbits.T3RD16 = 1;
    TMR3L = 0;
    TMR3H = 0;
    
    T3CONbits.TMR3ON = nENABLE;   
}

void Set_Timer3(unsigned int data_timer )
{
    TMR3H = data_timer >> 8;        
    TMR3L = data_timer & 0x00FF; 
}

unsigned int Get_Timer3()
{
    unsigned int Data;
    Data = TMR3H << 8 | TMR3L;
    return Data;
}
/*====================================================================================================*/
void Config_Timer5( void ) 
{
    T5CONbits.TMR5CS1 = 1;
    T5CONbits.TMR5CS0 = 0;
    /*TMRxCS<1:0>: Timer1/3/5 Clock Source Select bits
    11 =Reserved. Do not use.
    10 =Timer1/3/5 clock source is pin or oscillator:
    If TxSOSCEN = 0:
    External clock from TxCKI pin (on the rising edge)
    If TxSOSCEN = 1:
    Crystal oscillator on SOSCI/SOSCO pins
    01 =Timer1/3/5 clock source is system clock (FOSC)
    00 =Timer1/3/5 clock source is instruction clock (FOSC/4)*/
    
    T5CONbits.T5CKPS1 = 0;
    T5CONbits.T5CKPS0 = 0;
    /*TxCKPS<1:0>: Timer1/3/5 Input Clock Prescale Select bits
    11 = 1:8 Prescale value
    10 = 1:4 Prescale value
    01 = 1:2 Prescale value
    00 = 1:1 Prescale value*/
    
    T5CONbits.T5SOSCEN = 0;
    /*TxSOSCEN: Secondary Oscillator Enable Control bit
    1 = Dedicated Secondary oscillator circuit enabled
    0 = Dedicated Secondary oscillator circuit disabled*/
    
    T5CONbits.T5SYNC = 1;
    /*
     TxSYNC: Timer1/3/5 External Clock Input Synchronization Control bit
    TMRxCS<1:0> = 1X
    1 = Do not synchronize external clock input
    0 = Synchronize external clock input with system clock (FOSC)
    TMRxCS<1:0> = 0X
    This bit is ignored. Timer1/3/5 uses the internal clock when TMRxCS<1:0> = 1X.*/
    
    T5CONbits.T5RD16 = 1;     
    /*TxRD16: 16-Bit Read/Write Mode Enable bit
    1 = Enables register read/write of Timer1/3/5 in one 16-bit operation
    0 = Enables register read/write of Timer1/3/5 in two 8-bit operation*/

    T5CONbits.TMR5ON = 1;       
    /*TMRxON: Timer1/3/5 On bit
    1 = Enables Timer1/3/5
    0 = Stops Timer1/3/5
    Clears Timer1/3/5 Gate flip-flop*/
        
    TMR5IP = 1;     //PRIORIDADE ALTA
    TRISCbits.RC2 = 1;
    PIR5bits.TMR5IF = 0;
    TMR5 = 65534;
}

void Set_Timer5(unsigned int data_timer )
{
    TMR5H = data_timer >> 8;        
    TMR5L = data_timer & 0x00FF;  
}

unsigned int Get_Timer5()
{
    unsigned int Data;
    Data = TMR5H << 8 | TMR5L;
    return Data;
}
/*****************************************************************************************************/

/******************************************* 8 Bit�s Timer *******************************************/
void Config_Timer2( void )
{
/*0000 = 1:1 Postscaler         TxOUTPS<3:0>: TimerX Output Postscaler Select bits
 *0001 = 1:2 Postscaler
 *0010 = 1:3 Postscaler
 *0011 = 1:4 Postscaler
 *0100 = 1:5 Postscaler
 *0101 = 1:6 Postscaler
 *0110 = 1:7 Postscaler
 *0111 = 1:8 Postscaler
 *1000 = 1:9 Postscaler
 *1001 = 1:10 Postscaler
 *1010 = 1:11 Postscaler
 *1011 = 1:12 Postscaler
 *1100 = 1:13 Postscaler
 *1101 = 1:14 Postscaler
 *1110 = 1:15 Postscaler
 *1111 = 1:16 Postscaler*/

        T2CONbits.T2OUTPS0 = 1;
        T2CONbits.T2OUTPS1 = 1;
        T2CONbits.T2OUTPS2 = 1;
        T2CONbits.T2OUTPS3 = 1;
                
/* TxCKPS<1:0>: Timer2-type Clock Prescale Select bits
*** 00 = Prescaler is 1
*** 01 = Prescaler is 4
*** 1x = Prescaler is 16*/
        T2CONbits.T2CKPS0 = 1;
        T2CONbits.T2CKPS1 = 1;

        T2CONbits.TMR2ON = nENABLE;
}

void Set_Timer2(unsigned int data_timer )
{
    TMR2 = data_timer;  
}

unsigned int Get_Timer2()
{
    unsigned int Data;
    Data = TMR2;
    return Data;
}
/*====================================================================================================*/
void Config_Timer4( void )
{
/*0000 = 1:1 Postscaler         TxOUTPS<3:0>: TimerX Output Postscaler Select bits
 *0001 = 1:2 Postscaler
 *0010 = 1:3 Postscaler
 *0011 = 1:4 Postscaler
 *0100 = 1:5 Postscaler
 *0101 = 1:6 Postscaler
 *0110 = 1:7 Postscaler
 *0111 = 1:8 Postscaler
 *1000 = 1:9 Postscaler
 *1001 = 1:10 Postscaler
 *1010 = 1:11 Postscaler
 *1011 = 1:12 Postscaler
 *1100 = 1:13 Postscaler
 *1101 = 1:14 Postscaler
 *1110 = 1:15 Postscaler
 *1111 = 1:16 Postscaler*/

        T4CONbits.T4OUTPS0 = 0;
        T4CONbits.T4OUTPS1 = 0;
        T4CONbits.T4OUTPS2 = 0;
        T4CONbits.T4OUTPS3 = 0;
                
/* TxCKPS<1:0>: Timer2-type Clock Prescale Select bits
*** 00 = Prescaler is 1
*** 01 = Prescaler is 4
*** 1x = Prescaler is 16*/
        T4CONbits.T4CKPS0 = 0;
        T4CONbits.T4CKPS1 = 0;
        
        T4CONbits.TMR4ON = nENABLE;
}

void Set_Timer4(unsigned int data_timer )
{
    TMR4 = data_timer;  
}

unsigned int Get_Timer4()
{
    unsigned int Data;
    Data = TMR4;
    return Data;
}
/*====================================================================================================*/
void Config_Timer6( void )
{
/*0000 = 1:1 Postscaler         TxOUTPS<3:0>: TimerX Output Postscaler Select bits
 *0001 = 1:2 Postscaler
 *0010 = 1:3 Postscaler
 *0011 = 1:4 Postscaler
 *0100 = 1:5 Postscaler
 *0101 = 1:6 Postscaler
 *0110 = 1:7 Postscaler
 *0111 = 1:8 Postscaler
 *1000 = 1:9 Postscaler
 *1001 = 1:10 Postscaler
 *1010 = 1:11 Postscaler
 *1011 = 1:12 Postscaler
 *1100 = 1:13 Postscaler
 *1101 = 1:14 Postscaler
 *1110 = 1:15 Postscaler
 *1111 = 1:16 Postscaler*/

        T6CONbits.T6OUTPS0 = 0;
        T6CONbits.T6OUTPS1 = 0;
        T6CONbits.T6OUTPS2 = 0;
        T6CONbits.T6OUTPS3 = 0;
                
/* TxCKPS<1:0>: Timer2-type Clock Prescale Select bits
*** 00 = Prescaler is 1
*** 01 = Prescaler is 4
*** 1x = Prescaler is 16*/
        T6CONbits.T6CKPS0 = 0;
        T6CONbits.T6CKPS1 = 0;
        
        T6CONbits.TMR6ON = nENABLE;

}

void Set_Timer6(unsigned int data_timer )
{
    TMR6 = data_timer;  
}

unsigned int Get_Timer6()
{
    unsigned int Data;
    Data = TMR6;
    return Data;
}
/*====================================================================================================*/
void Config_Timer0( void )
{
    T0CONbits.T0PS0 = 0;
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS2 = 0;
/*T0PS<2:0>: Timer0 Prescaler Select bits
 *111 = 1:256 prescale value
 *110 = 1:128 prescale value
 *101 = 1:64 prescale value
 *100 = 1:32 prescale value
 *011 = 1:16 prescale value
 *010 = 1:8 prescale value
 *001 = 1:4 prescale value
 *000 = 1:2 prescale value*/
        
    T0CONbits.T08BIT = 0;
    /*1 = Timer0 is configured as an 8-bit timer/counter
      0 = Timer0 is configured as a 16-bit timer/counter*/
    
    T0CONbits.PSA =  0;
    T0CONbits.T0SE = 0;
    T0CONbits.T0CS = 0;
    
    T0CONbits.TMR0ON = nENABLE;
            

}

void Set_Timer0(unsigned int data_timer )
{
    TMR0H = data_timer >> 8;        
    TMR0L = data_timer & 0x00FF; 
}

unsigned int Get_Timer0()
{
    unsigned int Data;
    Data = TMR0H << 8 | TMR0L;
    return Data;
}

/*****************************************************************************************************/


