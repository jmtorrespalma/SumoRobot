#ifndef _PCF8591_
#define _PCF8591_

#include <math.h>

#define PCF8591W 0x90
#define COMMAND 0
#define PCF8591R 0x91
#define REF 5.0
#define MAX 255


float pcf_measure_volts(){
   int r;
   float volts;

   i2c_start();
	delay_us(50);
	i2c_write(PCF8591W);
	delay_us(50);
   i2c_write(COMMAND);
	delay_us(50);
   i2c_stop();


   i2c_start();
   delay_us(50);
	i2c_write(PCF8591R);
   
  // r = i2c_read(); //Leemos el malo
   delay_us(50);

   r = i2c_read(0); //Leemos el byte bueno
   delay_us(50);  
	i2c_stop();
   
   volts = (float) r / MAX * REF;   

   return volts;
}

int pcf_measure_cm(){
   float volts;
   int cm;
      
   volts = pcf_measure_volts();
   
   cm = (int) 11 - (log10(volts - 0.2) / log10(1.135));
   
   return cm;

}



#endif
