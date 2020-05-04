#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "switches.h"

unsigned char red = 0, green = 0;
unsigned char changed = 0;


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}


void led_update(){
  if (switch_state_changed) {
    char ledFlags = LED_RED; /* by default, no LEDs on */

    ledFlags |= switch_state_down ? LED_GREEN : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}



void toggle_green(){

  green=1;

  red=0;

}





char toggle_red()/* always toggle! */{
    static char state = 0;
    switch (state) {
    case 0:

        red = 1;

        state = 1;

        break;



    case 1:

        red = 0;

        state = 0;

        break;



    }
    return 1;/* always changes an led */
}

 
