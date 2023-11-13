#pragma once


/**
 * @brief Struct representing the previous states of the buttons.
 * 
 */
typedef struct ButtonOldstates
{
    unsigned char ok : 1;
    unsigned char left : 1;
    unsigned char right : 1;
    unsigned char menu : 1;
    unsigned char feed : 1;
    unsigned char love : 1;
    unsigned char sleep : 1;
    unsigned char wash : 1;
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

