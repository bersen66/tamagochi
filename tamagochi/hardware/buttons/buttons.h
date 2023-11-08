#pragma once


typedef struct ButtonOldstates
{
    unsigned short ok : 1;
    unsigned short left : 1;
    unsigned short right : 1;
    unsigned short menu : 1;
    unsigned short feed : 1;
    unsigned short love : 1;
    unsigned short sleep : 1;
    unsigned short wash : 1;
} ButtonOldstates;

extern ButtonOldstates btns;


static inline void InitButtons()
{
    DDD0_bit = 0; // Set D0 pin as input
    DDD1_bit = 0; // Set D1 pin as input
    DDD2_bit = 0; // Set D2 pin as input
    DDD3_bit = 0; // Set D3 pin as input

    DDB0_bit = 0; // Set B0 pin as input
    DDB1_bit = 0; // Set B1 pin as input
    DDB2_bit = 0; // Set B2 pin as input
    DDB3_bit = 0; // Set B3 pin as input
}

static inline void ClearButtonOldstates()
{
    btns.ok = 0;
    btns.left = 0;
    btns.right = 0;
    btns.menu = 0;
    btns.feed = 0;
    btns.love = 0;
    btns.sleep = 0;
    btns.wash = 0;
}

// Хз будет ли работать
static inline void PollButtons()
{
    btns.ok = PINB0_bit;
    btns.left = PINB1_bit;
    btns.right = PINB2_bit;
    btns.menu = PINB3_bit;

    btns.feed = PIND0_bit;
    btns.love = PIND1_bit;
    btns.sleep = PIND2_bit;
    btns.wash = PIND3_bit;
}