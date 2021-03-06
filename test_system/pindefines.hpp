#include <stdint.h>
#define COMP_PWR_REL_DDR DDRH
#define COMP_PWR_BTN_DDR DDRB
#define COMP_PWR_REL_PIN PH5 //TODO: change pin to PH5 (8)
#define COMP_PWR_BTN_PIN PB6
#define COMP_PWR_REL_PORT PORTH
#define COMP_PWR_BTN_PORT PORTB

//9 - wht lamps, 10 - 5v, 11 - motors

#define LAMP_RED_PORT PORTE // TODO: make a connection to relays of white lamps
#define LAMP_RED_DDR DDRE
#define LAMP_RED_PIN PE5

#define PWR_5V_PORT PORTB
#define PWR_5V_DDR DDRB
#define PWR_5V_PIN PB4

#define MOTORS_REL_PWR_PORT PORTB
#define MOTORS_REL_PWR_DDR DDRB
#define MOTORS_REL_PWR_PIN PB5

#define LAMP_WHT_PORT PORTH
#define LAMP_WHT_DDR DDRH
#define LAMP_WHT_PIN PH6

#define M1AIN PA0 // 22 -> 1 (IN A on scheme)
#define M1BIN PA1 // 23 -> 6
#define M1PWM PA2 // 24 -> 5

#define M2AIN PC4 // 33 -> 1
#define M2BIN PC3 // 34 -> 6
#define M2PWM PC2 // 35 -> 5

#define RGTSTSWPIN PH4 //was PB0 PB1 -> 7
#define LFTSTSWPIN PH3 // -> 6

#define RH_LIMIT ((PINH & _BV(RGTSTSWPIN)) != 0)
#define RH_NOT_LIMIT !RH_LIMIT
#define LH_LIMIT ((PINH & _BV(LFTSTSWPIN)) != 0)
#define LH_NOT_LIMIT !LH_LIMIT

#define SONAR_DATA_LEN 3
#define SONAR_COUNT 2

// head distance sensor trig 4 echo 5 
#define TRIG_1_PIN PB0 //53
#define ECHO_1_PIN PB1 //52
#define TRIG_2_PIN PB3 //50
#define ECHO_2_PIN PB2 //51
#define HEAD_TRIG_PIN PF4 
#define HEAD_ECHO_PIN PF5

#define RS485_TRSM PF3
#define RS485_RECV PF2

#define TIMER_1_SECOND 5120

//#define RH_GO_UP PORTL |= _BV(RHUP)
//#define RH_GO_DOWN PORTL |= _BV(RHDOWN)
#define LH_STOP PORTG &= ~_BV(LEFTHAND)
#define RH_STOP PORTG &= ~_BV(RIGHTHAND)

#define RIGHTHAND PG1 // 40
#define LEFTHAND PG0 // 41
#define RHUP PL4 // 45
#define LHUP PL5 // 44
#define RHDOWN PL6 // 43
#define LHDOWN PL7 // 42

#define LH_IS_NEW_CMD (LH_Command != old_LH_Command)
#define RH_IS_NEW_CMD (RH_Command != old_RH_Command)

#define HANDS_PWM_UP 254
#define HANDS_PWM_DN 100

// hands cmds
#define RIGHTHANDUP 16761405
#define RIGHTHANDDOWN 16748655
#define RIGHTHANDSTOP 16756815
#define LEFTHANDUP 16720605
#define LEFTHANDDOWN 16769055
#define LEFTHANDSTOP 16738455
#define NOCMD 0x00

