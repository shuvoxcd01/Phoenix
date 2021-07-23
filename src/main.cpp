#include <Arduino.h>
#include <Wire.h>
#include "mario_melody.h"
#include <rtc.h>
#include "lcd.h"

#define backLedPin 13
#define tempPin A0   // thermometer connects to A0
#define buzzerPin 9
#define ldrPin A2

#define ledPin1 6
#define ledPin2 8
#define ledPin3 10
#define ledPin4 A1


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LCD lcd(rs, en, d4, d5, d6, d7);
RTC _clock = RTC();

// bool is_led_on = false;

void sing_startup_melody()
{
  sing(1, buzzerPin, backLedPin);
}

// inline float get_temperature_in_celsius()
// {
//   return analogRead(tempPin) * 0.48828125;

// }

// inline void hour_bell()
// {
//     tone(buzzerPin,2000,1000);     
// }

// inline void check_and_set_led()
// {
//     if((analogRead(ldrPin) < 50))
//     {
//       if (!is_led_on)
//       {
//         is_led_on = true;
//         digitalWrite(backLedPin, HIGH);
//       }
//     }
//     else
//     {
//       if(is_led_on)
//       {
//         is_led_on = false;
//         digitalWrite(backLedPin, LOW); 
//       }
//     }   
// }

void check_rtc(){
    if (_clock.check_availability()){
    lcd.print("RTC OK.");
  }
  else{
    lcd.print("Problem with RTC");
  }
  delay(500);
}

void setup ()
{


  // pinMode(ledPin1, OUTPUT);
  // pinMode(ledPin2, OUTPUT);
  // pinMode(ledPin3, OUTPUT);
  // pinMode(ledPin4, OUTPUT);

  // digitalWrite(ledPin1, HIGH);
  // digitalWrite(ledPin2, HIGH);
  // digitalWrite(ledPin3, HIGH);
  // digitalWrite(ledPin4, HIGH);
  
  // pinMode(backLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

    check_rtc();
    lcd.play_startup_animation(sing_startup_melody);
}

void loop () 
{
    lcd.print_time_and_temperature(_clock.get_current_time(),  30);

    // if(_clock.is_hour_start()){
    //   hour_bell(); 
    // }

    // check_and_set_led();
    delay(500);
}
