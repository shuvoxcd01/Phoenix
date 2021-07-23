#pragma once
#include "RTClib.h"
#include <LiquidCrystal.h>

class LCD{
    private:
    LiquidCrystal *lcd;

    public:
    LCD(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    ~LCD();
    void play_startup_animation(void (*startup_melody_func)());
    void print_time_and_temperature(DateTime now, float temperature);
    void print(const char str[]);
};