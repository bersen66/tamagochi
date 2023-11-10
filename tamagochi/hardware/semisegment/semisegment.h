#pragma once

void InitSemisegments();

unsigned short MaksOf(char c);

void Timer0Overflow_ISR() org IVT_ADDR_TIMER0_OVF;

void PrintEatSemisegment();

void PrintLoveSemisegment();

void PrintRestSemisegment();

void PrintBathSemisegment();

void PrintCoolSemisegment();

void ClearSemisegment();