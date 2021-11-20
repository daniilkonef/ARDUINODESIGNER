/*
 Name:		Processor1.ino
 Created:	20.11.2021 22:55:08
 Author:	user
*/

//D:\Projects\my_electronics\arduino-designer\Simulations\Project5\Version1\VisualStudio\Processor1

#include <Wire.h>
#include <MCP342x.h>

/* Demonstrate the use of convertAndRead().
 */


 // 0x68 is the default address for all MCP342x devices
uint8_t address = 0x68;
MCP342x adc = MCP342x(address);



void setup(void)
{
    Serial.begin(9600);
    Serial.println("hello");
    delay(10);
    Wire.begin();

    // Enable power for MCP342x (needed for FL100 shield only)
    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);

    // Reset devices
    MCP342x::generalCallReset();
    delay(1); // MC342x needs 300us to settle, wait 1ms

    // Check device present
    Wire.requestFrom(address, (uint8_t)1);
    if (!Wire.available()) {
        Serial.print("No device found at address ");
        Serial.println(address, HEX);
        while (1)
            ;
    }

}

void loop(void)
{
    long value = 0;
    MCP342x::Config status;
    // Initiate a conversion; convertAndRead() will wait until it can be read
    uint8_t err = adc.convertAndRead(MCP342x::channel1, MCP342x::oneShot,
        MCP342x::resolution16, MCP342x::gain1,
        1000000, value, status);
    if (err) {
        Serial.print("Convert error: ");
        Serial.println(err);
    }
    else {
        Serial.print("Value: ");
        Serial.println(value);
    }

    delay(1000);
}