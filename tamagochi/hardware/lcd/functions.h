#pragma once

#include <tamagochi/hardware/time/time.h>

void InitLCD();

void ClearLCD();

void PrintLCD(char* text);

void ShiftLeftLCD(int offset, dur_t timeout);

void ShiftRightLCD(int offset, dur_t timeout);
