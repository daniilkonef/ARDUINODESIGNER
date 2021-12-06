/*
 Name:		Processor1.ino
 Created:	04.07.2021 17:59:04
 Author:	Konev
*/

// Это MASTER CPU на шине I2C
#include <Wire.h>
byte data_received_from_I2C_bus;					// data_received_from_I2C_bus

void setup()
{
	Wire.begin();									// join I2C bus as Master Этот процессор подключился к шине I2C в качестве Мастер, поэтому в скобках НЕ был указан никакой адрес 
	Serial.begin(9600);
	Serial.println(" ");			// Выводим 
	Serial.println("Author Konev");		// Выводим 
	Serial.println("i am i2c transmitter");		// Выводим 
	data_received_from_I2C_bus = 255;				// initialize global variables - Инициалллизация глобальных переменных 
}

void loop()
{
	//// Отправка данных	После сохранения значения с пина A0 в переменную value_pot, мы можем отправить значение по I2C.Отправка данных по I2C включает в себя три функции.
	Wire.beginTransmission(0x08); // информирует шину о том, что мы будем посылать данные to slave device 8 (0x08)
	Wire.write("K");        // идет отправка байта
	Wire.endTransmission();       // После отправки данных нам необходимо освободить сеть, чтобы позволить другим устройствам общаться по сети. Это делается с помощью функции Wire.endTransmission().
	Serial.println("K");
	delay(500);
}
