#include <tamagochi/hardware/buttons/buttons.h>

void InitButtons()
{
    DDA0_bit = 0; // Set A0 pin as input
    DDA1_bit = 0; // Set A1 pin as input
    DDA2_bit = 0; // Set A2 pin as input
    DDA3_bit = 0; // Set A3 pin as input

    DDB0_bit = 0; // Set B0 pin as input
    DDB1_bit = 0; // Set B1 pin as input
    DDB2_bit = 0; // Set B2 pin as input
    DDB3_bit = 0; // Set B3 pin as input
}

enum ButtonState buttons_states[8] = {
    BTN_STATE_UP,
    BTN_STATE_UP,
    BTN_STATE_UP,
    BTN_STATE_UP,
    BTN_STATE_UP,
    BTN_STATE_UP,
    BTN_STATE_UP,
    BTN_STATE_UP,
};

void UpdateButton(unsigned short *port, unsigned short pin, enum ButtonCode bc)
{
    if (Button(port, pin, 1, 1))
    {
        switch (buttons_states[bc])
        {
        case BTN_STATE_UP:
            buttons_states[bc] = BTN_STATE_PRESSED;
            break;
        default:
            buttons_states[bc] = BTN_STATE_DOWN;
            break;
        }
    }
    else
    {
        switch (buttons_states[bc])
        {
        case BTN_STATE_DOWN:
            buttons_states[bc] = BTN_STATE_RELEASED;
            break;
        default:
            buttons_states[bc] = BTN_STATE_UP;
            break;
        }
    }
}

void PollButtons()
{
    UpdateButton(&PINA, 0, BUTTON_OK);
    UpdateButton(&PINA, 1, BUTTON_LEFT);
    UpdateButton(&PINA, 2, BUTTON_RIGHT);
    UpdateButton(&PINA, 3, BUTTON_MENU);

    UpdateButton(&PINB, 0, BUTTON_FEED);
    UpdateButton(&PINB, 1, BUTTON_LOVE);
    UpdateButton(&PINB, 2, BUTTON_SLEEP);
    UpdateButton(&PINB, 3, BUTTON_WASH);
}

bool ButtonIsPressed(enum ButtonCode bc)
{
    return buttons_states[bc] == BTN_STATE_PRESSED;
}

bool ButtonIsReleased(enum ButtonCode bc)
{
    return buttons_states[bc] == BTN_STATE_RELEASED;
}

bool ButtonIsDown(enum ButtonCode bc)
{
    return buttons_states[bc] == BTN_STATE_DOWN;
}

bool ButtonIsUp(enum ButtonCode bc)
{
    return buttons_states[bc] == BTN_STATE_UP;
}