/*
 Name:		Project1_Processor1.ino
 Created:	17.06.2021 21:49:28
 Author:	Konev
*/

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);  // set baud rate at”9600”
}

// the loop function runs over and over again until power down or reset
void loop() {
	Serial.println("KONEV");  // output and display characters beginning with Tep
	delay(1000);  // wait for 1 second
}
