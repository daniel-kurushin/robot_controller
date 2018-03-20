#include "d_sensors.hpp"
#include "Arduino.h"
#include "pindefines.hpp"
#include <math.h>

#define IDLE 0
#define TRIG 1
#define ECHO 2
#define SETP 3
#define FRUP 4
#define FRDN 5

#define K 4

volatile uint32_t time = 0;
volatile uint32_t ptme = 0;
volatile uint16_t sonar_distance = 0;

volatile uint8_t sonar_state = IDLE;
volatile uint8_t trig_state = IDLE; 
volatile uint8_t echo_state = IDLE;

uint8_t echo_pins[6] = {ECHO_1_PIN, ECHO_1_PIN};
uint8_t trig_pins[6] = {TRIG_1_PIN, TRIG_1_PIN};

uint8_t i = 0;

volatile uint16_t * sonarWork(uint16_t res[])
{
  switch (sonar_state)
  {
    case IDLE: {
      if (time - ptme > 100000) 
      {
        sonar_state = TRIG;
      }
      break;
    }
    case TRIG: {
      switch (trig_state)
      {
        case IDLE: {
          trig_state = FRUP;
          break;
        }
        case FRUP: {
          PORTB |= _BV(trig_pins[i]);
          ptme = time;
          trig_state = FRDN;
          break;
        }
        case FRDN: {
          if (time - ptme > 0)
          {
            PORTB &= ~_BV(trig_pins[i]);
            trig_state = IDLE;
            sonar_state = ECHO;
            echo_state = IDLE;
          }
          break;
        }
      }
      break;
    }
    case ECHO: {
      switch (echo_state)
      {
        case IDLE: {
          if (PINB & _BV(echo_pins[i]))
          {
            ptme = time;
            echo_state = FRUP;
          }
          break;
        }
        case FRUP: {
          if (! (PINB & _BV(echo_pins[i])))
          {
            sonar_distance = (time - ptme) / K;
            echo_state = FRDN;
          }
          break;
        }
        case FRDN: {
          echo_state = IDLE;
          sonar_state = IDLE;
          res[0] = i;
          res[1] = sonar_distance;
          if (i++ > sizeof(echo_pins)) i = 0;
          break;
        }
      }
      break;
    }
  }

  return res;
}

// void setup() 
// { 
//   pinMode(TRIG_PIN, OUTPUT);
//   pinMode(ECHO_PIN,  INPUT);
//   pinMode(SERV_PIN, OUTPUT);
//   pinMode(13, OUTPUT);
//   Serial.begin(115200);
//   a0.attach(SERV_PIN);
// } 
// time = micros();
//   if (time < ptme) ptme = time;
//   avg += sonarWork() * 100; cnt++;
// //  servoWork(pos);

//   if (time - pos_ptme > 10000)
//   {
//     pos = map(avg / cnt, 0, 300, MIN, MAX);
//     if (pos < MIN) pos = MIN;
//     if (pos > MAX) pos = MAX;
//     pos_ptme = time;
//     cnt = 0;
//     avg = 0;
//     a0.write(pos);
//   }
//   R0; G0; B0;


