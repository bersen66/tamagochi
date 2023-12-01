#pragma once

#include <tamagochi/hardware/time/constants.h>
/**
 * @brief Suspends the execution of the calling thread for a specified amount of time.
 * 
 * @param duration The duration of time to sleep, in milliseconds.
 */
void Sleep(const dur_t duration);