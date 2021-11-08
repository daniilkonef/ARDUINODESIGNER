#include <iom8.h>
#include <util/delay.h>
#include <avr/io.h>
#include "lcd_lib.h"
#include "mcp3001.h"

#define F_CPU 4000000

int main()
{
unsigned int adc=0;
char buffer[5]="";

SPI_MasterInit();
LCDinit();

adc=ReceiveADC();
sprintf(buffer, "%i", adc);//выводим только цифровой код
LCDclr();
LCDGotoXY(0,0);
LCDstring(buffer, sizeof(buffer)-1);
while(1);
}
