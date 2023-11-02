#pragma once
#include <tamagochi/utils/bool.h>

enum ButtonCode
{
    BUTTON_OK = 0,
    BUTTON_LEFT = 1,
    BUTTON_RIGHT = 2,
    BUTTON_MENU = 3,
    BUTTON_FEED = 4,
    BUTTON_LOVE = 5,
    BUTTON_SLEEP = 6,
    BUTTON_WASH = 7,
};

enum ButtonState {
    BTN_STATE_UP = 0,
    BTN_STATE_PRESSED = 1,
    BTN_STATE_DOWN = 2,
    BTN_STATE_RELEASED = 3,
};

void InitButtons();

void PollButtons();

bool ButtonIsPressed(enum ButtonCode bc);

bool ButtonIsReleased(enum ButtonCode bc);

bool ButtonIsDown(enum ButtonCode bc);

bool ButtonIsUp(enum ButtonCode bc);