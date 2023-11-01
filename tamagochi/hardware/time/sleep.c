#include <tamagochi/hardware/time/sleep.h>

void Sleep(const unsigned long duration) {
    vDelay_ms(duration);
}