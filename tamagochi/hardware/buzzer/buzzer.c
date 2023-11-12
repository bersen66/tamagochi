#include <tamagochi/hardware/buzzer/buzzer.h>

void InitBuzzer()
{
    Sound_Init(&PORTD, 5);
}