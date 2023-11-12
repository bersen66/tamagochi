#pragma once

#include <hardware/time/constants.h>

void InitBuzzer();

void Beep(unsigned freq_in_hz, dur_t time);