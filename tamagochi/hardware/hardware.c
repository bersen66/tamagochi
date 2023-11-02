#include <tamagochi/hardware/hardware.h>

#include <tamagochi/hardware/buttons/buttons.h>
#include <tamagochi/hardware/lcd/lcd.h>
#include <tamagochi/hardware/time/time.h>

void InitHardware()
{
    InitButtons();
    InitLCD();
}