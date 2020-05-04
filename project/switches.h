#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3		/* switch1 is p1.3 */
#define SWITCHES (SW1 | SW2 | SW3 | SW4)		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed, tempo,s1,s2,s3,s4; /* effectively boolean */

typedef unsigned char u_char;
typedef unsigned int u_int;

#endif // included
