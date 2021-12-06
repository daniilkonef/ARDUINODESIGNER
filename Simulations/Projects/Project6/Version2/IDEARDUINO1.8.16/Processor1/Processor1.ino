#include <MCP3202.h> // 12-bit resolution

//D13 - CK
//D12 - DOUT
//D11 - DIN
//D10 - CS

// You can also refer to this website!
// Thanks to baturman for making this schematic.
// https://easyeda.com/baturman/arduino-uno-r3-mcp3202-wiring-diagram

/**
 *  This code shall return the voltage value in terms of a decimal value.
 *  4096 means the voltage is equal to Vdd, while 0 means voltage is Vss.
 */


MCP3202 ADC1 = MCP3202(10); //the CS pin number. Change according to requirement.

float Vpwr = 4.096; //change according to your Vdd value.
float channel0 = 0.0;
float channel1 = 0.0;
float Vdiff=0.0;
float voltage0=0.0;
float voltage1=0.0;
float R1=2000.0;
float R2=2000.0;
float R3=2000.0;
float RQ=0.0;

void setup() {
  // put your setup code here, to run once:
  ADC1.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  channel0 = ADC1.readChannel(0);
  channel1 = ADC1.readChannel(1);
  Serial.println("Serial.println(channel1,6);");
  Serial.println(channel0,6);
  Serial.println("Serial.println(channel2,6);");
  Serial.println(channel1,6);
   
  voltage0 = (channel0*Vpwr)/4096.0;
  voltage1 = (channel1*Vpwr)/4096.0;
  Serial.println("Serial.println(voltage0,6);");
  Serial.println(voltage0,6);
  Serial.println("Serial.println(voltage1,6);");
  Serial.println(voltage1,6);
  Serial.println("Serial.println(voltage0-voltage1,6);");
  Serial.println(voltage0-voltage1,6);

  Vdiff = voltage0-voltage1;
  Serial.println("Serial.println(Vdiff,6);");
  Serial.println(Vdiff,6);

  float x1;
  float x2;
  x1 = R2*Vpwr-(R1+R2)*Vdiff;
  x2 = R1*Vpwr+(R1+R2)*Vdiff;
  RQ=(x1/x2)*R3;
  Serial.print("RQ=");
  Serial.println(RQ,6);
  delay(1000);
}
