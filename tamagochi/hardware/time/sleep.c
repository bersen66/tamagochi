#include <tamagochi/hardware/time/sleep.h>
#include <tamagochi/hardware/time/constants.h>

void Sleep(const dur_t duration) {
    vDelay_ms(duration);
}