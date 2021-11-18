/*
 Name:		Project1_Processor2.ino
 Created:	17.06.2021 22:24:24
 Author:	Konev
*/


/*
  Данный код позволяет принять данные, идущие из порта, в строку (String) без "обрывов"
*/
String String1 = "";
boolean recieved_with_success_flag;
void setup() 
{
    Serial.begin(9600);
    Serial.println("PROCESSOR2");               // вывести
}
void loop() 
{
    while (Serial.available() > 0) // ПОКА есть что то на входе    
    {         
        String1 = String1 + (char)Serial.read();        // забиваем строку принятыми данными
        recieved_with_success_flag = true;                   // поднять флаг что получили данные
        delay(10);                              // НУЖНА МЕЛКАЯ ЗАДЕРЖКА! Без неё работает некорректно!
    }
    if (recieved_with_success_flag == true)     // если данные получены
    {                      
        Serial.print("RX: ");               // вывести
        Serial.print(String1);               // вывести
        String1 = "";                          // очистить
        recieved_with_success_flag = false;                  // опустить флаг
    }
}
