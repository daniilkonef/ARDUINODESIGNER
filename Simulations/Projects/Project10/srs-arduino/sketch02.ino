#include <GyverOLED.h>
GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;


#include <dht.h>
dht DHT;
#define DHT11_PIN 2

void setup() {
  oled.init();        // инициализация
  oled.clear();       // очистка
  oled.setScale(2);   // масштаб текста (1..4)
  oled.home();        // курсор в 0,0
  oled.print("ООО АСБ");
  delay(100);

  oled.setScale(1);
  oled.setCursor(0, 3); // курсор на начало 3 строки
  oled.print("инж. Даниил Конев");

  
  oled.setCursorXY(20, 50); // курсор на (20, 50)
  //float pi = 3.14;
  oled.print("Кабинет 205");
  //oled.print(pi);
}
void loop() {
  DHT.read11(DHT11_PIN);
  oled.print(DHT.humidity);
  delay(100);
  oled.print("Кабинет 205");
}