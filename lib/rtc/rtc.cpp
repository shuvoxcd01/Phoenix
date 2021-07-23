#include <Wire.h>
#include<RTClib.h>
#include "rtc.h"

bool RTC::check_availability(bool useSerialMonitor = false){
    if (useSerialMonitor){
      while (!Serial);   
      Serial.begin(9600);
      Serial.println("Serial Monitor Started.");
      delay(500);
    }

    if (!this->rtc.begin()) {
      if (useSerialMonitor){
        Serial.println("Couldn't find RTC");
        delay(500);
      }

      return false;
    }

    if (!this->rtc.isrunning()) {
      if (useSerialMonitor){
        Serial.println("RTC is NOT running!");
        delay(500);
      }

      return false;
    }

    return true;
  }

void RTC::set_date_and_time(){
      this->rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

      // following lines adjusts the time that elapsed during compilation of code.
      // Please, do not run this code after the computer's second reaches 55.  Wait for 5 seconds.

      DateTime cur_time = this->rtc.now();
      this->rtc.adjust(DateTime(cur_time.year(), cur_time.month(), cur_time.day(), cur_time.hour(), cur_time.minute(), cur_time.second()+5));

}

DateTime RTC::get_current_time(){
    return this->rtc.now();
}

bool RTC::is_hour_start(){
    DateTime cur_time = this->rtc.now();

    return (cur_time.minute() == 0) and (cur_time.second() == 0);
}

