#include <dht.h>
dht DHT;
#define DHT11_PIN     13

#include <GyverOLED.h>
GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;

void setup()
{
  Serial.begin(9600);
  
  oled.init();        // инициализация
  oled.clear();       // очистка
  
  oled.setScale(2);   // масштаб текста (1..4)
  oled.home();        // курсор в 0,0
  oled.print("OOO АСБ");
  
  oled.setScale(1);
  oled.setCursor(0, 3); // курсор на начало 3 строки
  oled.print("Даниил Конев, каб.205");
  
  
  
  
}


void loop()
{
  // READ DATA
  
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    //Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    //Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    //Serial.print("Time out error,\t"); 
    break;
    case DHTLIB_ERROR_CONNECT:
        //Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        //Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        //Serial.print("Ack High error,\t");
        break;
    default: 
    //Serial.print("Unknown error,\t"); 
    break;
  }
  // DISPLAY DATA
  String hum(DHT.humidity,0);
  String tem(DHT.temperature,0);
  Serial.println("\t Датчик DHT11: влажность %: "+hum); 
  Serial.println("\t Датчик DHT11: температ. С: "+tem); 
  
  oled.setCursor(0, 5); // курсор на начало 4 строки
  oled.print("Влажность: "+hum + " %");
  oled.setCursor(0, 6); // курсор на начало 4 строки
  oled.print("Температ.: "+tem + " C");
  
  delay(1000);
  
}


// -- END OF FILE --

