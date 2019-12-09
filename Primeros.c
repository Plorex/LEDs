/*
 * File:   Primeros.c
 * Author: Plorex
 * Descripcion: Este programa encenderá dos leds por medio de un pulsador P2
 * Created on November 4, 2019, 10:41 PM
 */

/*//////////////////////////////////INICIO\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#include <xc.h>             /*Inicio, la libreria xc.h que incluye registros y 
                              bits por defecto del PIC*/

/*//////////////Configuracion de Bits y definicion del cristal\\\\\\\\\\\\\\*/
#include "ConfigBits.h"     //Configuracion de Bits
#define _XTAL_FREQ 4000000  // Definicion del cristal

/*/////////////////////////Declaracion de Variables\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*///////////////////////y definicion de puertos\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
#define SW RC0
#define led LATDbits.LATD1
#define led1 LATCbits.LATC1

void InitPort()
    {
    LATD = 0; // Inicializo salidas del puerto D en 0V
    TRISC = 0x01; // configuro el pin RC0 como entrada y los demás como salida
    TRISDbits.RD1 = 0; // configuro el pin RD1 como salida
    }

/*//////////////////////////////Programa Principal\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
void main(void) 
    {
    InitPort();
    while(1)
        {
        if(SW == 0)
            {
            while(SW == 0)
                {
                led = 1;
                led1 = 1;
                __delay_ms(1000);                
                }
            }
        else
            {
            led = 0;
            led1 = 0;
            }
        }
    }
