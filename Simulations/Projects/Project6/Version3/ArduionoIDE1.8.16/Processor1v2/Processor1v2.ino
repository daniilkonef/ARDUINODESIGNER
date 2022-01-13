#include <Wire.h>
#include <MCP342x.h> // The MCP3423 is a two channel low-noise, high accuracy delta-sigma A/D converter with differential inputs and up to 18 bits of resolution.


// https://alexgyver.ru/lessons/variables-types/ 
// https://www.microchip.com/en-us/product/MCP3423
// https://github.com/stevemarple/MCP342x

/* Demonstrate the use of convertAndRead().
 */



byte address = 0x68; // 0x68 is the default address for all MCP342x devices // byte это  uint8_t
MCP342x ADC_MCP3423 = MCP342x(address);

float Vpwr = 4.096; //change according to your Vdd value.
long value_of_channel0 = 0;
long value_of_channel1 = 0;
float Vdiff=0.0;
float voltage0=0.0;
float voltage1=0.0;
float R1=1000.0;
float R2=1000.0;
float R3=1000.0;
float RQ=0.0;
long MyGain=1;

void setup(void)
{
  Serial.begin(9600);
  Wire.begin();

  
  
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
  MCP342x::Config status;
  // Initiate a conversion; convertAndRead() will wait until it can be read
  byte error_of_channel1 = ADC_MCP3423.convertAndRead(MCP342x::channel1, MCP342x::oneShot, MCP342x::resolution18, MCP342x::gain1, 1000000, value_of_channel0, status);
  if (error_of_channel1) 
  {
    Serial.print("ADC_MCP3423 made converting error on channel 1: ");  
    Serial.println(error_of_channel1);
  }
  else 
  {
//    Serial.println("Serial.println(address, HEX);");
//    Serial.println(address, HEX);
//    Serial.println("Serial.println(address, BIN);");
//    Serial.println(address, BIN);
//    Serial.print("value_of_channel0: ");
//    Serial.println(value_of_channel0);
//    Serial.println("Serial.println(value_of_channel0, BIN);");
//    Serial.println(value_of_channel0, BIN);
  }
  

  byte error_of_channel2 = ADC_MCP3423.convertAndRead(MCP342x::channel2, MCP342x::oneShot, MCP342x::resolution18, MCP342x::gain1, 1000000, value_of_channel1, status);
  if (error_of_channel2) 
  {
    Serial.print("ADC_MCP3423 made converting error on channel 2: ");
    Serial.println(error_of_channel2);
  }
  else 
  {
//    Serial.println("Serial.println(address, HEX);");
//    Serial.println(address, HEX);
//    Serial.println("Serial.println(address, BIN);");
//    Serial.println(address, BIN);
//    Serial.print("value_of_channel1: ");
//    Serial.println(value_of_channel1);

    //Serial.print("pow(2,18): "); Serial.print(pow(2,18));
    //Serial.print("pow(2,18): "); Serial.println(pow(2, round(MCP342x::resolution18)) );
    //Serial.print( "MCP342x::resolution18: " );
    //Serial.println( MCP342x::resolution18 );
  }

    voltage0 = value_of_channel0*( Vpwr/pow(2,18) )*2; //MCP342x::resolution18
    voltage1 = value_of_channel1*( Vpwr/pow(2,18) )*2; //MCP342x::resolution18

    Serial.print("value_of_channel1: ");
    Serial.println(value_of_channel1);
    Serial.println("Serial.println(value_of_channel1, BIN);");
    Serial.println(value_of_channel1, BIN);
    
//    Serial.println("Serial.println(voltage0,6);");
//    Serial.println(voltage0,6);
//    Serial.println("Serial.println(voltage1,6);");
//    Serial.println(voltage1,6);
//    Serial.println("Serial.println(voltage0-voltage1,6);");
//    Serial.println(voltage0-voltage1,6);

    Vdiff = (voltage0-voltage1)/MyGain;
//    Serial.println("Serial.println(Vdiff,6);");
//    Serial.println(Vdiff,6);
  
    float x1; float x2;
    x1 = R2*Vpwr-(R1+R2)*Vdiff;
    x2 = R1*Vpwr+(R1+R2)*Vdiff;
    RQ=(x1/x2)*R3;
    Serial.print("RQ="); Serial.println(RQ,2);
    delay(1000);

    // Enable power for MCP342x (needed for FL100 shield only)
   pinMode(9, OUTPUT);
   digitalWrite(9, HIGH);
}
