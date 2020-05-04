#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"
#include "lcddraw.h"
#include "lcdutils.h"

char switch_state_down, switch_state_changed, tempo,s1,s2,s3,s4; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p1val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  s1 = (p1val & SW1) ? 1 : 0; //switch 1

  s2 = (p1val & SW2) ? 1 : 0; //switch 2

  s3 = (p1val & SW3) ? 1 : 0; //switch 3

  s4 = (p1val & SW4) ? 1 : 0; //switch 4
  
    buzzer_set_period(0);
  
  if (!(p1val & s1)) {
    state_advance();
    tempo = 12;
    star_wars();
    clearScreen(COLOR_RED);
    //clearScreen(COLOR_BLUE);
    drawString5x7(20,50, "Emmanuel's project", COLOR_YELLOW, COLOR_BLACK);
    switch_state_changed = 1;
  }

  else if (!(s2 & p1val)) {
    buzzer_set_period(473);
    switch_state_changed = 2;
    led_update();
  }

  else if (!(s3 & p1val)) {
    buzzer_set_period(723);
    switch_state_changed = 3;
    led_update();
  }

  else if (!(s4 & p1val)) {
    tempo = 50;
    mario();
    switch_state_changed = 4;
    led_update();
  }
  
  //next_state();
  switch_state_changed = 1;
  led_update();
}
