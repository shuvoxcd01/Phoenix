#include<Arduino.h>
#include "lcd.h"
#include "RTClib.h"

char daysOfTheWeek[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};


LCD::LCD(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7){
    this->lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
    this->lcd->begin(16,2);
}

LCD::~LCD(){
    delete this->lcd;
}

void LCD::play_startup_animation(void (*startup_melody_func)()){
  this->lcd->clear();
  this->lcd->print("Powering On");
  startup_melody_func();
  this->lcd->clear();
  this->lcd->noDisplay();
  delay(200);
  this->lcd->display();
}

void LCD::print_time_and_temperature(DateTime now, float temperature){
      this->lcd->clear();
     
      this->lcd->setCursor(0,0);
      this->lcd->print(now.day(), DEC);
      this->lcd->print('/');
      this->lcd->print(now.month(), DEC);
      this->lcd->print('/');
      this->lcd->print(now.year(), DEC);
      this->lcd->print(' ');
      this->lcd->print(temperature);
      this->lcd->print((char)223);
      this->lcd->print('C');
    
      this->lcd->setCursor(0,1);
     
      this->lcd->print(now.twelveHour(), DEC);
      this->lcd->print(':');
      this->lcd->print(now.minute(), DEC);
      this->lcd->print(':');
      this->lcd->print(now.second(), DEC);
      this->lcd->print(" ");
      // this->lcd->print(now.isPM() ? "PM" : "AM");
  
      this->lcd->print(' ');
      this->lcd->print(daysOfTheWeek[now.dayOfTheWeek()]);
  }

void LCD::print(const char str[]){
    this->lcd->clear();
    this->lcd->print(str);
}