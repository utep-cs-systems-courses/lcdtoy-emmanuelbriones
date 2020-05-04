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

  clearScreen(COLOR_BLUE);
  drawString5x7(20,30, " WELCOME.", COLOR_RED, COLOR_GREEN);
  //drawString5x7(10,60, " menu:", COLOR_WHITE, COLOR_BLUE);
  drawString5x7(10,75, " Option 1", COLOR_WHITE, COLOR_BLUE);
  drawString5x7(10,85, " Option 2 ", COLOR_WHITE, COLOR_BLUE);
  drawString5x7(10,95, " Option 3", COLOR_WHITE, COLOR_BLUE);
  drawString5x7(10,105, " Option 4", COLOR_WHITE, COLOR_BLUE);

  or_sr(0x18);
}
