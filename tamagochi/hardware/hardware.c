#include <tamagochi/hardware/hardware.h>

#include <tamagochi/hardware/buttons/buttons.h>
#include <tamagochi/hardware/lcd/lcd.h>
#include <tamagochi/hardware/semisegment/semisegment.h>
#include <tamagochi/hardware/buzzer/buzzer.h>

/**
 * Initializes the hardware components of the Tamagochi device.
 * This function initializes the buttons and the LCD screen.
 */
void InitHardware()
{
    //InitSemisegments();
    InitBuzzer();
    InitButtons();
    InitLCD();
}