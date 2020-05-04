#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"


void main() {
  configureClocks();
  switch_init();
  buzzer_init();
  led_init();
  enableWDTInterrupts();
  
  lcd_init();

  u_char width = screenWidth, height = screenHeight;
  //show the options to the user
  clearScreen(COLOR_BLUE);
  drawString5x7(30,30, " WELCOME!", COLOR_WHITE, COLOR_BLACK);
  drawString5x7(0,45, "Option 1:Two squares", COLOR_WHITE, COLOR_BLUE);
  drawString5x7(0,55, "Option 2:Cool Phrase ", COLOR_WHITE, COLOR_BLUE);
  drawString5x7(0,65, "Option 3: Go MINERS", COLOR_WHITE, COLOR_BLUE);
  drawString5x7(0,75, "Option 4:Triangle", COLOR_WHITE, COLOR_BLUE);

  or_sr(0x18);
}
