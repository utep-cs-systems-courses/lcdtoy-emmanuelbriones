#ifndef led_included
#define  led_included

#include <msp430.h>

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char red, green;
extern unsigned char changed;

void led_init();		/* initialize LEDs */
void led_update();		/* update leds */
char toggle_red();
void toggle_green();


#endif
