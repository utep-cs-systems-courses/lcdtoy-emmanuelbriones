#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "stateMachines.h"

static int counter = 0;
static int counter2 = 0;

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void star_wars() {
  switch (counter) {
  case 0: buzzer_set_period(950); counter++; break;
  case 1:
  case 6:
  case 11: buzzer_set_period(630); counter++; break;
  case 2:
  case 7:
  case 12:
  case 14: buzzer_set_period(710); counter++; break;
  case 3:
  case 8:
  case 13: buzzer_set_period(750); counter++; break;
  case 4:
  case 9:
  case 15: buzzer_set_period(840); if (counter == 15) {counter = 0;} else{counter++;}; break;
  case 5:
  case 10: buzzer_set_period(475); counter++; break;
  }
}

void mario() {
  switch (counter2) {
  case 0:
  case 1:
  case 2:
  case 4: buzzer_set_period(750); counter2++; break;
  case 3: buzzer_set_period(950); counter2++; break;
  case 5: buzzer_set_period(630); counter2++; break;
  case 6: buzzer_set_period(1260); counter2 = 0; break;
  }
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

