#ifndef _TARJETA_
#define _TARJETA_

#include <18F4550.h>

#fuses WRTB, NOLVP, NOPBADEN, VREGEN, HSPLL, PLL5, USBDIV, NOWDT

/***********************************************************
      EVITAMOS LA ZONA DE MEMORIA ASIGNADA AL MONITOR
***********************************************************/

#define LOADER_END	0x7FF
#define LOADER_SIZE	0x6FF

#build(reset=LOADER_END+1, interrupt=LOADER_END+9)
#org 0, LOADER_END {}
//#org 0x82A, 0x7FFF


/***********************************************************
           FUNCIONES PARA MOVER LOS MOTORES
MX_H() : Mueve el motor en sentido horario
MX_A() : Mueve el motor en sentido anti-horario
MX_P() : Para el motor
***********************************************************/

void M1_A(){
	output_high(PIN_A1);
	output_high(PIN_D7);
	output_low(PIN_D6);
}

void M1_H(){
	output_high(PIN_A1);
	output_low(PIN_D7);
	output_high(PIN_D6);
}

void M1_P(){
	output_high(PIN_A1);
	output_low(PIN_D7);
	output_low(PIN_D6);
}

void M2_A(){
	output_high(PIN_A0);
	output_high(PIN_C2);
	output_low(PIN_D5);
}

void M2_H(){
	output_high(PIN_A0);
	output_low(PIN_C2);
	output_high(PIN_D5);
}

void M2_P(){
	output_high(PIN_A0);
	output_low(PIN_C2);
	output_low(PIN_D5);
}

void M3_A(){
	output_high(PIN_A2);
	output_low(PIN_B2);
	output_high(PIN_E0);
}

void M3_H(){
	output_high(PIN_A2);
	output_high(PIN_B2);
	output_low(PIN_E0);
}

void M3_P(){
	output_high(PIN_A2);
	output_low(PIN_B2);
	output_low(PIN_E0);
}

void M4_A(){
	output_high(PIN_A3);
	output_low(PIN_E2);
	output_high(PIN_E1);
}

void M4_H(){
	output_high(PIN_A3);
	output_high(PIN_E2);
	output_low(PIN_E1);
}

void M4_P(){
	output_high(PIN_A3);
	output_low(PIN_E2);
	output_low(PIN_E1);
}


/***********************************************************
            MACRO PARA LEER EL PULSADOR P2
***********************************************************/

#define P2	(!input(PIN_B4))

/***********************************************************
              MACROS PARA MANEJAR EL LED
***********************************************************/

#define led_on()	output_high(PIN_A5)
#define led_off()	output_low(PIN_A5)

/***********************************************************
           DEFINICION DE LAS E/S DIRECTAS
***********************************************************/

#define ES0	PIN_A4
#define ES1	PIN_B3
#define ES2	PIN_B5
#define ES3	PIN_B6
#define ES4	PIN_B7
#define ES5	PIN_C7
#define ES6	PIN_C6
#define ES7	PIN_C1
#define ES8	PIN_C0

/***********************************************************
        MACROS PARA LEER LOS SENSORES FIJOS INX
***********************************************************/

#define IN1		input(PIN_D0)
#define IN2		input(PIN_D1)
#define IN3		input(PIN_D2)
#define IN4		input(PIN_D3)
#define IN5		input(PIN_D4)
//IN6 ES UNA E/S CONFIGURABLE
//#define IN6		input(ES0)
//#define IN6		input(ES1)
// ... O CUALQUIER OTRA E/S DIRECTA

/***********************************************************
            DIRECTIVA PARA EL USO DEL I2C
***********************************************************/
#use I2C(master, sda=PIN_B0, scl=PIN_B1)

#endif
