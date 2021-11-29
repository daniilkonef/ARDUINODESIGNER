#include <Wire.h>
#include <MCP342x.h> // The MCP3423 is a two channel low-noise, high accuracy delta-sigma A/D converter with differential inputs and up to 18 bits of resolution.


// https://alexgyver.ru/lessons/variables-types/ 
// https://www.microchip.com/en-us/product/MCP3423

/* Demonstrate the use of convertAndRead().
 */



byte address = 0x68; // 0x68 is the default address for all MCP342x devices // byte IS uint8_t
MCP342x ADC_MCP3423 = MCP342x(address);

void setup(void)
{
  Serial.begin(9600);
  Wire.begin();

  // Enable power for MCP342x (needed for FL100 shield only)
  // pinMode(9, OUTPUT);
  // digitalWrite(9, HIGH);
  
  // Reset devices
  MCP342x::generalCallReset();
  delay(1); // MC342x needs 300us to settle, wait 1ms
  
  // Check device present
  Wire.requestFrom(address, (byte)1);
  if (Wire.available() == false)  // 
  {
    Serial.print("No ADC chip device found at address ");
    Serial.println(address, HEX);
    Serial.println(address);
    while (1) {};  // показал сообщение и сидим тут бесконечно без движения, инженер должен начать исправлять проблему
  }

}

void loop(void)
{
  long value = 0;
  MCP342x::Config status;
  // Initiate a conversion; convertAndRead() will wait until it can be read
  byte error_of_channel1 = ADC_MCP3423.convertAndRead(MCP342x::channel1, MCP342x::oneShot, MCP342x::resolution18, MCP342x::gain1, 1000000, value, status);
  if (error_of_channel1) 
  {
    Serial.print("ADC_MCP3423 converting error on channel 1: ");
    Serial.println(error_of_channel1);
  }
  else 
  {
    Serial.println("Serial.println(address, HEX);");
    Serial.println(address, HEX);
    Serial.println("Serial.println(address, BIN);");
    Serial.println(address, BIN);
    Serial.print("Value: ");
    Serial.println(value);
  }
  

  byte error_of_channel2 = ADC_MCP3423.convertAndRead(MCP342x::channel2, MCP342x::oneShot, MCP342x::resolution18, MCP342x::gain1, 1000000, value, status);
  if (error_of_channel2) 
  {
    Serial.print("ADC_MCP3423 converting error on channel 1: ");
    Serial.println(error_of_channel2);
  }
  else 
  {
    Serial.println("Serial.println(address, HEX);");
    Serial.println(address, HEX);
    Serial.println("Serial.println(address, BIN);");
    Serial.println(address, BIN);
    Serial.print("Value: ");
    Serial.println(value);
  }
  
  delay(1000);
}
