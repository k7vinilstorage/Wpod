#include "display.h"

IpodDisplay::IpodDisplay(U8G2_SSD1306_128X64_NONAME_F_HW_I2C &display) {
    Wire.begin(33,32);
    u8g2 = &display;
}

void IpodDisplay::setupDisplay() {
    u8g2->begin();
    u8g2->clearBuffer();
    u8g2->setFontMode(1);
    u8g2->setBitmapMode(1);
    u8g2->drawXBMP(1, 0, 127, 64, ipod_w);
    u8g2->sendBuffer();
}

void IpodDisplay::ChangeMenu() {
}

void IpodDisplay::StateDrawSD() {
    if(sd_state == 0) {
        u8g2->drawXBMP(111, 46, 14, 15, image_micro_sd_no_card_bits);
    }
    else {
        u8g2->drawXBMP(112, 46, 12, 15, image_micro_sd_bits);
    }
}

void IpodDisplay::MainMenuDraw(int pos) {
    u8g2->clearBuffer();
    u8g2->setFont(u8g2_font_6x10_tr);
    StateDrawSD();
    u8g2->drawXBMP(94, 46, 14, 15, image_bluetooth_not_connected_bits);
    u8g2->drawXBMP(97, 3, 24, 13, image_battery_empty_bits);
    u8g2->drawLine(89, 0, 89, 63);
    u8g2->drawLine(90, 64, 90, 0);

    switch(pos) {
        case 0:
        u8g2->drawXBMP(0, 2, 89, 58, music);
        break;
        case 1:
        u8g2->drawXBMP(0, 3, 89, 57, settings);
        break;
        case 2:
        u8g2->drawXBMP(0, 3, 89, 57, now_playing);
        break;
        case 3:
        u8g2->drawXBMP(0, 3, 89, 58, shuffle);
        break;
    }

    if(is_playing) {
        u8g2->drawXBMP(103, 23, 15, 15, image_music_play_bits);
    }
    else {
        u8g2->drawXBMP(103, 23, 15, 15, image_music_pause_bits);
    }

    u8g2->sendBuffer();
}

void IpodDisplay::MainMenu(char cmd) {
    switch(cmd) {
        case 'z':
            MainMenuDraw(main_menu_pos);
            break;
        case 'd':
            if(main_menu_pos < 3) {
                main_menu_pos++;
                MainMenuDraw(main_menu_pos);
            }
            break;
        case 'u':
            if(main_menu_pos > 0) {
                main_menu_pos--;
                MainMenuDraw(main_menu_pos);
            }
            break;
        case 'e':
            ChangeMenu();
            break;
    } 
    MainMenuDraw(main_menu_pos);
}


