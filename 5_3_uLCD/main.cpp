#include "mbed.h"
#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2); // uLCD_4DGL(Tx pin, Rx pin, rst pin);


int main()
{
      uLCD.printf("\nHello uLCD World\n"); //Default Green on black text
      ThisThread::sleep_for(30s);
}
