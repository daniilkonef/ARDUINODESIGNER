

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd_monitor(rs, en, d4, d5, d6, d7);



void setup() 
{
	Serial.begin(9600);  // set baud rate atФ9600Ф

	lcd_monitor.begin(16, 2); // почему то весь этот код монитора перестает работать если вынести его из функции —етапа 
	lcd_monitor.begin(16, 2);

	lcd_monitor.setCursor(2, 0);
	lcd_monitor.print("DANIIL KONEV");
	delay(2000);

	/*lcd_monitor.setCursor(2, 0);
	lcd_monitor.print("www.ARDUINO-");
	lcd_monitor.setCursor(2, 1);
	lcd_monitor.print("DESIGNER.RU");
	delay(1000);*/
}



void loop() {
	//MyADC1();
	if (analogRead(A0) >= analogRead(A1) ) 
	{	
		float val;  // define variable
		float volt;
		float millivolt;
		float Celsius;


		val = analogRead(A0);  // read the analog value of the sensor and assign it to val
		//Serial.print("val=");  // output and display characters beginning with Tep
		//Serial.println(val);   // output and display characters beginning with Tep
		//Serial.print("ARDUINO-DESIGNER.RU, Summer: ");   // output and display characters beginning with Tep
		Serial.print("Summer: ");   // output and display characters beginning with Tep
		volt = (5.0 / 1023.0) * val;  //volt=(5/1024)*val;
		millivolt = volt * 1000;
		//Serial.print("millivolt=");  // output and display characters beginning with Tep
		//Serial.println(millivolt);   // output and display characters beginning with Tep

		Celsius = millivolt / 10.0;
		Serial.print("Celsius= +");    // output and display characters beginning with Tep
		Serial.println(Celsius, 1);  // output and display characters beginning with Tep

		delay(1000);  // wait for 1 second

		lcd_monitor.clear();
		lcd_monitor.setCursor(0, 0);
		lcd_monitor.print("Summer");
		lcd_monitor.setCursor(0, 1);
		lcd_monitor.print("Celsius= +");
		lcd_monitor.print(Celsius);
		lcd_monitor.print("C");

	}

	if (analogRead(A1) > analogRead(A0)) 
	{
		float val;  // define variable
		float volt;
		float millivolt;
		float Celsius;


		val = analogRead(A1);  // read the analog value of the sensor and assign it to val
		//Serial.print("val=");  // output and display characters beginning with Tep
		//Serial.println(val);   // output and display characters beginning with Tep
		//Serial.print("ARDUINO-DESIGNER.RU, Winter: ");   // output and display characters beginning with Tep

		volt = (5.0 / 1023.0) * val;  //volt=(5/1024)*val;
		millivolt = volt * 1000;
		//Serial.print("millivolt=");  // output and display characters beginning with Tep
		//Serial.println(millivolt);   // output and display characters beginning with Tep

		Celsius = millivolt / 10.0;
		Serial.print("Celsius= -");    // output and display characters beginning with Tep
		Serial.println(Celsius, 1);  // output and display characters beginning with Tep

		lcd_monitor.clear();
		lcd_monitor.setCursor(0, 0);
		lcd_monitor.print("Winter");
		lcd_monitor.setCursor(0, 1);
		lcd_monitor.print("Celsius= -");
		lcd_monitor.print(Celsius);
		lcd_monitor.print("C");

		delay(1000);  // wait for 1 second
	}
	
}


float MyADC1() 
{
	float val;  // define variable
	float volt;
	float millivolt;
	float Celsius;

	
	val = analogRead(A0);  // read the analog value of the sensor and assign it to val
	Serial.print("val=");  // output and display characters beginning with Tep
	Serial.println(val);   // output and display characters beginning with Tep

	volt = (5.0 / 1023.0) * val;  //volt=(5/1024)*val;
	millivolt = volt * 1000;
	Serial.print("millivolt=");  // output and display characters beginning with Tep
	Serial.println(millivolt);   // output and display characters beginning with Tep

	Celsius = millivolt / 10.0;
	Serial.print("Celsius=");    // output and display characters beginning with Tep
	Serial.println(Celsius, 1);  // output and display characters beginning with Tep

	delay(1000);  // wait for 1 second
	return millivolt;

}