// uLCD-144-G2 basic text demo program for uLCD-4GL LCD driver library

// https://os.mbed.com/users/4180_1/code/4DGL-uLCD-SE/docs/tip/uLCD__4DGL_8h_source.html uLCD_4DGL.h

#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

int main()
{

    // basic printf demo = 16 by 18 characters on screen
    uLCD.printf("\nHello uLCD World\n"); //Default Green on black text
    uLCD.printf("\n  Starting Demo...");
    uLCD.text_width(4); //4X size text
    uLCD.text_height(4);

    uLCD.color(RED);

    for (int i=10; i>=0; --i) {
        uLCD.locate(1,2);
        uLCD.printf("%2d",i);
        ThisThread::sleep_for(500ms);
    }

//    uLCD.cls();
//    uLCD.printf("Change baudrate......");
//	uLCD.baudrate(3000000); //jack up baud rate to max for fast display
    //if demo hangs here - try lower baud rates
    //
    // printf text only full screen mode demo
    uLCD.background_color(BLUE);
    uLCD.cls();
    uLCD.locate(0,0);
    uLCD.color(WHITE);
    uLCD.textbackground_color(BLUE);
//    uLCD.set_font(FONT_7X8);
//    uLCD.text_mode(OPAQUE);
    int i=0;
    while (i<64) {
        if(i % 16 == 0) uLCD.cls();
        uLCD.printf("TxtLine %2D Page %D\n", i%16, i/16);
        i++; //16 lines with 18 charaters per line
    }
    ThisThread::sleep_for(500ms);
//demo graphics commands
    uLCD.background_color(BLACK); // need to be used before the uLCD.cls();
    uLCD.cls();
    uLCD.background_color(DGREY);
    uLCD.cls();
    uLCD.filled_circle(60, 50, 30, 0xFF00FF);
    uLCD.triangle(120, 100, 40, 40, 10, 100, 0x0000FF);
    uLCD.line(0, 0, 80, 60, 0xFF0000);
    uLCD.filled_rectangle(50, 50, 100, 90, 0x00FF00);
    uLCD.pixel(60, 60, BLACK);
    
    uLCD.circle(0, 60, 10, uLCD.read_pixel(120, 70)); // void circle(int x , int y , int radius, int color); // 0~127
    uLCD.set_font(FONT_7X8);
    uLCD.text_mode(TRANSPARENT);
    uLCD.text_bold(ON);
    uLCD.text_char('B', 9, 8, BLACK);
    uLCD.text_char('I',10, 8, BLACK);
    uLCD.text_char('G',11, 8, BLACK);
    uLCD.text_italic(ON); // tilted
    uLCD.text_inverse(ON);
    uLCD.text_underline(ON);
    uLCD.text_string("This is a test of string", 1, 4, FONT_7X8, WHITE);
}

