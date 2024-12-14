#ifndef Display_H
#define Display_H

#include <U8g2lib.h>
#include <Wire.h>
#include "images.h"

class IpodDisplay {
    public:
        int sd_state = 0;

        IpodDisplay(U8G2_SSD1306_128X64_NONAME_F_HW_I2C &display);
        void setupDisplay();
        void MainMenu(char cmd);

    private:
        U8G2_SSD1306_128X64_NONAME_F_HW_I2C *u8g2;
        int main_menu_pos;
        bool is_playing;

        void MainMenuDraw(int pos);
        void ChangeMenu();
        void StateDrawSD();
};

#endif