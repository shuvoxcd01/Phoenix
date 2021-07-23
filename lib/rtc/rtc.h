#pragma once

#include <Wire.h>
#include "RTClib.h"

class RTC{
  private:
    RTC_DS1307 rtc;

  public:
    bool check_availability(bool useSerialMonitor = false);
    void set_date_and_time();
    DateTime get_current_time();
    bool is_hour_start();
};

