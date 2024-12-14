#include "display.h"
#include "input.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/ 32, /* data=*/ 33, /* reset=*/ U8X8_PIN_NONE);

IpodDisplay display(u8g2);
IpodInput input;


void setup() {
    display.setupDisplay();
}

void loop() {
    switch(display.selected_menu) {
        case 0:
            display.MainMenu(input.DetectInput());
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }
    
}