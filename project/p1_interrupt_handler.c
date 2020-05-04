#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

/* Switch on P1 (S2) */
void __interrupt_vec(WDT_VECTOR) WDT(){
    static char decisecond_count = 0;
    if(++decisecond_count == tempo){
        int repeat = 1;
        while(repeat <= 5){
            int cnt = 0;
            while(cnt < 30000){
                cnt++;
            }
            repeat++;
        }
    switch_interrupt_handler();
    decisecond_count = 0;
    }

}

