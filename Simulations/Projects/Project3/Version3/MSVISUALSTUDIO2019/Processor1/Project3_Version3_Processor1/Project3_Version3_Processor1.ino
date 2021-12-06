/*
 Name:		Project3_Version3_Processor1.ino
 Created:	09.07.2021 23:13:52
 Author:	konev
*/


#include <GyverTimers.h>
#include <GyverButton.h>
#include <AnalogKey.h>

// Проект 18 - Дисплей с одной цифрой
#define PIN_DATA1 6 // к выводу 14 микросхемы 74HC595
#define PIN_LATCH1 8 // к выводу 12 микросхемы 74HC595
#define PIN_CLOCK1 10 // к выводу 11 микросхемы 74HC595

#define PIN_DATA2 3 // к выводу 14 микросхемы 74HC595
#define PIN_LATCH2 4 // к выводу 12 микросхемы 74HC595
#define PIN_CLOCK2 2 // к выводу 11 микросхемы 74HC595

#define PIN_CLOCK3 5 // к выводу 11 микросхемы 74HC595
#define PIN_DATA3 6 // к выводу 14 микросхемы 74HC595
#define PIN_LATCH3 7 // к выводу 12 микросхемы 74HC595

// Подготовить массив с комбинациями сегментов
// для цифр 0 - 9 и букв A - F (из табл. 6.2)
byte digits[] = { 252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142 };
byte index_of_segment1 = 0;
byte index_of_segment2 = 0;
byte index_of_segment3 = 0;

GButton Button1(17);
GButton Button2(18);
GButton Button3(19);


void setup()
{
	Serial.begin(9600);
	Serial.println(" ");     // 
	Serial.println("Author DANIIL KONEV");     // 
	Serial.println("Blog ARDUINO-DESIGNER.RU");     // 

	Button1.setTickMode(AUTO); // Button1.tick();  // обязательная функция отработки, она должна постоянно опрашиваться
	Button2.setTickMode(AUTO); // Button2.tick();  // обязательная функция отработки. Должна постоянно опрашиваться
	Button3.setTickMode(AUTO); // Button3.tick();  // обязательная функция отработки. Должна постоянно опрашиваться
	
	pinMode(PIN_LATCH1, OUTPUT);
	pinMode(PIN_CLOCK1, OUTPUT);
	pinMode(PIN_DATA1, OUTPUT);

	pinMode(PIN_LATCH2, OUTPUT);
	pinMode(PIN_CLOCK2, OUTPUT);
	pinMode(PIN_DATA2, OUTPUT);

	pinMode(PIN_LATCH3, OUTPUT);
	pinMode(PIN_CLOCK3, OUTPUT);
	pinMode(PIN_DATA3, OUTPUT);
}

void loop()
{
		digitalWrite(PIN_LATCH1, LOW);
		shiftOut(PIN_DATA1, PIN_CLOCK1, LSBFIRST, digits[index_of_segment1] + 1); // +1, чтобы включить точку
		digitalWrite(PIN_LATCH1, HIGH);

		digitalWrite(PIN_LATCH2, LOW);
		shiftOut(PIN_DATA2, PIN_CLOCK2, LSBFIRST, digits[index_of_segment2]); // вывести символы 0-9, A-F без точки 
		digitalWrite(PIN_LATCH2, HIGH);

		digitalWrite(PIN_LATCH3, LOW);
		shiftOut(PIN_DATA3, PIN_CLOCK3, LSBFIRST, digits[index_of_segment3]); // вывести символы 0-9, A-F без точки 
		digitalWrite(PIN_LATCH3, HIGH);
		//delay(1000);

		if (Button1.isSingle())
		{
			index_of_segment1++;
			if (index_of_segment1 > 9) index_of_segment1 = 0;	// слежу чтобы цифра не смогла превысить число 9, а то она не сможет отобразиться на одноциферном индикаторе
		}

		if (Button2.isSingle())
		{
			index_of_segment2++;
			if (index_of_segment2 > 9) index_of_segment2 = 0;	// слежу чтобы цифра не смогла превысить число 9, а то она не сможет отобразиться на одноциферном индикаторе
		}

		if (Button3.isSingle())
		{
			index_of_segment3++;
			if (index_of_segment3 > 9) index_of_segment3 = 0;	// слежу чтобы цифра не смогла превысить число 9, а то она не сможет отобразиться на одноциферном индикаторе
		}
}
