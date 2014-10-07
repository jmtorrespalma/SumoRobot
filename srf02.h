
#ifndef _SRF02_
#define _SRF02_

#define SRF02W 0xE0
#define COMMAND 0
#define SRF02R 0xE1
#define MEASUREH 2
#define MEASUREL 3

unsigned int16 srf_measure_cm(){
unsigned int16 m, m2;

	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(0x51);
	delay_us(50);
	i2c_stop();
	delay_ms(80);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(MEASUREH);
	delay_us(50);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02R);
	delay_us(50);
	m = i2c_read();
	delay_us(50);
	m2 = i2c_read(0);
	delay_us(50);
	i2c_stop();

	m = (m << 8) | m2;
	return m;
}

unsigned int16 srf_measure_in(){
unsigned int16 m, m2;

	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(0x50);
	delay_us(50);
	i2c_stop();
	delay_ms(80);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(MEASUREH);
	delay_us(50);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02R);
	delay_us(50);
	m = i2c_read();
	delay_us(50);
	m2 = i2c_read(0);
	delay_us(50);
	i2c_stop();

	m = (m << 8) | m2;
	return m;
}

unsigned int16 srf_measure_us(){
unsigned int16 m, m2;

	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(0x52);
	delay_us(50);
	i2c_stop();
	delay_ms(80);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(MEASUREH);
	delay_us(50);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02R);
	delay_us(50);
	m = i2c_read();
	delay_us(50);
	m2 = i2c_read(0);
	delay_us(50);
	i2c_stop();

	m = (m << 8) | m2;
	return m;
}

unsigned int16 srf_false_measure_cm(){
unsigned int16 m, m2;

	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(0x57);
	delay_us(50);
	i2c_stop();
	delay_ms(80);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(MEASUREH);
	delay_us(50);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02R);
	delay_us(50);
	m = i2c_read();
	delay_us(50);
	m2 = i2c_read(0);
	delay_us(50);
	i2c_stop();

	m = (m << 8) | m2;
	return m;
}

unsigned int16 srf_false_measure_in(){
unsigned int16 m, m2;

	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(0x56);
	delay_us(50);
	i2c_stop();
	delay_ms(80);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(MEASUREH);
	delay_us(50);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02R);
	delay_us(50);
	m = i2c_read();
	delay_us(50);
	m2 = i2c_read(0);
	delay_us(50);
	i2c_stop();

	m = (m << 8) | m2;
	return m;
}

unsigned int16 srf_false_measure_us(){
unsigned int16 m, m2;

	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(0x58);
	delay_us(50);
	i2c_stop();
	delay_ms(80);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(MEASUREH);
	delay_us(50);
	i2c_start();
	delay_us(50);
	i2c_write(SRF02R);
	delay_us(50);
	m = i2c_read();
	delay_us(50);
	m2 = i2c_read(0);
	delay_us(50);
	i2c_stop();

	m = (m << 8) | m2;
	return m;
}

void srf_burst(){

	i2c_start();
	delay_us(50);
	i2c_write(SRF02W);
	delay_us(50);
	i2c_write(COMMAND);
	delay_us(50);
	i2c_write(0x5C);
	delay_us(50);
	i2c_stop();
}

#endif
