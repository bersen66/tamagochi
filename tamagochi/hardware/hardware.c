#include <tamagochi/hardware/hardware.h>

#include <tamagochi/hardware/buttons/buttons.h>
#include <tamagochi/hardware/lcd/lcd.h>
#include <tamagochi/hardware/semisegment/semisegment.h>



void InitHardware()
{
    TCCR0 = 0x00;   // ClkI/O/64 (From prescaler)
    SREG_I_bit = 1; // Interrupt enable
    TOIE0_bit = 1;  // Timer0 overflow interrupt enable

    InitSemisegments();
    InitButtons();
    InitLCD();
}