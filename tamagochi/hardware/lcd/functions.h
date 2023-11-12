#pragma once

#include <tamagochi/hardware/time/time.h>

/**
 * @brief Initializes the LCD.
 */
void InitLCD();

/**
 * @brief Clears the LCD screen.
 * 
 */
void ClearLCD();

/**
 * @brief Prints the given text on the LCD screen.
 * 
 * @param text The text to be printed on the LCD screen.
 */
void PrintLCD(char* text);

/**
 * Shifts the characters displayed on the LCD screen to the left by the specified offset.
 *
 * @param offset The number of characters to shift the display to the left.
 * @param timeout The duration of the shift operation.
 */
void ShiftLeftLCD(int offset, dur_t timeout);

/**
 * Shifts the characters displayed on the LCD screen to the right by a specified offset.
 * 
 * @param offset The number of characters to shift the display to the right.
 * @param timeout The duration of the shift animation in milliseconds.
 */
void ShiftRightLCD(int offset, dur_t timeout);
