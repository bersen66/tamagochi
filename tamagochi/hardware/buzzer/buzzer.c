#include <tamagochi/hardware/buzzer/buzzer.h>

#include <tamagochi/hardware/time/time.h>

void InitBuzzer()
{
    Sound_Init(&PORTD, 4);
}
void Beep(unsigned freq_in_hz, dur_t duration)
{
    Sound_Play(freq_in_hz, duration);
}