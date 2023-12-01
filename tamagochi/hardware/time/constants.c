#include <tamagochi/hardware/time/constants.h>

/**
 * @file constants.c
 * @brief Definition of time constants in milliseconds, seconds, minutes and hours.
 * 
 * This file contains the definition of time constants in different units of time such as milliseconds, seconds, minutes and hours.
 * MILLISECOND is defined as 1 millisecond.
 * SECOND is defined as 1000 milliseconds.
 * MINUTE is defined as 60 seconds.
 * HOUR is defined as 60 minutes.
 */

dur_t MILLISECOND = 1;
dur_t SECOND = 1000 * MILLISECOND;
dur_t MINUTE = 60 * SECOND;
dur_t HOUR = 60 * MINUTE;