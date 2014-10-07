#include "tarjeta.h"
#use delay (clock=48000000)
#include "srf02.h"
#include "pcf8591.h"


#define ATRAS 0
#define ADELANTE 1
#define IZQ 2
#define DER 3

int movim = ADELANTE;
int pwm = 255; //Velocidad
int val = 0;
int iter = 150; //Variable utilizada para contar iteraciones cuando encuentra una línea negra
int flag_der = 0; //Variable para controlar si la linea se ha detectado en la derecha
int flag_izq = 0; //Variable para controlar si la linea se ha detectado en la izquierda
int flag_atras = 0; //Variable para controlar si la linea se ha detectado atrás
int flag_obs = 1; //Se pone a uno si hay un obstáculo delante
int cont = 0;
int cont_bus = 0; //Cuenta las iteraciones en estado de busqueda

#INT_TIMER0
void tmr0_isr(){
   // El timer0 automáticamente se pone a 0
	val++;

   //Decidimos qué movimiento hacemos


   if (flag_der || flag_izq){ //Si se ha pisado una línea en la derecha o izq
      if (!val){ //Cuando valor vale 0, es decir, 256 llamadas a ISR
         if (cont < (iter / 2)){ //Vamos hacia atrás la mitad del tiempo
            ++cont;
            movim = ATRAS;
            pwm = 255;
            flag_obs = 0;

         }
         else if (cont < (iter/2 + iter/4)){ //Un cuarto hacia el lado opuesto al sensor enciendido, solo si no se detecta al enemigo
            ++cont;
            if (flag_der) //Si el derecho está a 1, movemos izq.
              movim = IZQ;
            else
               movim = DER;
         }

         else if (cont < iter && !flag_obs){ //El ultimo cuarto solo lo hace si no detecta nada delante
            ++cont;
            if (flag_der) //Si el derecho está a 1, movemos izq.
              movim = IZQ;
            else
               movim = DER;

         }
         else if(cont == iter || flag_obs){ //Cuando han pasado las iteraciones o se ha detectado algo, ponemos los flag a cero
            pwm = 150;
            flag_der = 0;
            flag_izq = 0;
            cont = 0;
            cont_bus = 0;
            movim = ADELANTE;
         }
      }
   }
   else if (flag_atras){ //Si se ha pisado una línea atrás
      if (!val){
         if (cont < (iter / 2)){
            pwm = 150;
            ++cont;
            movim = IZQ;
         }
         else if(cont == iter / 2){ //Cuando han pasado las iteraciones, ponemos los flag a cero
            cont = 0;
            flag_atras = 0;
            flag_obs = 0;
            movim = ADELANTE;
            cont_bus = 0;
         }
      }
   }
   else if (flag_obs){ //Si se detecta un objeto delante
      pwm = 255;
      movim = ADELANTE;
      cont_bus = 0;
   }

   //////Modo de búsqueda//////

   else if (cont_bus < (iter/2 + iter/4)){
      if (!val){
         ++cont_bus;
         pwm = 150;
         movim = ADELANTE;
      }
   }

   else if(cont_bus == (iter/2 + iter/4)){ //Decide a que lado gira
      if (!val){
         movim = DER;
         ++cont_bus;
      }
   }

   else if(cont_bus < iter){
      if (!val){
         ++cont_bus;
         pwm = 255;
      }
   }
   else if (cont_bus == iter)
      if (!val){
         cont_bus = 0;
      }

   //Dependiendo del movimiento, movemos un motor u otro

   M1_P(); //Hacemos esto para que al cambiar de sentido no de problemas.
   M2_P();
   M3_P();
   M4_P();


	if (val <= pwm){
      switch (movim){
         case ATRAS:
            M1_A();
            M2_A();
            M3_H();
            M4_A();
            break;

         case ADELANTE:
            M1_H();
            M2_H();
            M3_A();
            M4_H();
            break;

         case DER:
            M1_A();
            M2_A();
            M3_A();
            M4_H();
            break;

         case IZQ:
            M1_H();
            M2_H();
            M3_H();
            M4_A();
            break;

      }

   }

}


void main() {

unsigned int16 d_srf = 0;
int d_pcf = 0;

delay_ms(3000);

setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2|RTCC_8_BIT);
enable_interrupts(INT_TIMER0);
enable_interrupts(GLOBAL);

while (1){

   if (!flag_der && !flag_izq && !flag_atras){
      if (!IN1){ //Si se detecta negro en la derecha.
         flag_der = 1;
      }
      else if(!IN2){ //Si se detecta negro en la izquierda
         flag_izq = 1;
      }
      else if(!IN3){ //Si se detecta negro atrás
         flag_atras = 1;
      }
   }


   if (!flag_obs){
      d_pcf = pcf_measure_cm();
      d_srf = srf_measure_cm();

      flag_obs = (d_pcf+10 > d_srf && d_srf > d_pcf-10); //Si se detecta algo delante
   }
   




}

}
