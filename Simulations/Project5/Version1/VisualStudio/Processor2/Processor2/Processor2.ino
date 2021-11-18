/*
 Name:		Processor2.ino
 Created:	04.07.2021 22:38:00
 Author:	Konev
*/

// SLAVE
#include <Wire.h>
char received_char_data_from_i2c;               // data received from I2C bus

void setup()
{
	Serial.begin(9600);
	Serial.println(" ");			// Выводим 
	Serial.println("Author Konev");		// Выводим 
	Serial.println("i am i2c receiver");		// Выводим 
	Wire.begin(0x08);           // join I2C bus as Slave with address 0x08
	// event handler initializations
	Wire.onReceive(Run_Handler_for_received_data);    // мы добавляем функцию Wire.onReceive(handler) для регистрации функции (обработчика события), которая будет управлять полученными данными.
}

void loop()
{

}

// Run_Handler_for_received_data function
void Run_Handler_for_received_data(int numBytes)
{
	while (Wire.available()) {	// read all bytes received
		received_char_data_from_i2c = Wire.read();
	}
	Serial.println(received_char_data_from_i2c);		// Выводим время.
}

