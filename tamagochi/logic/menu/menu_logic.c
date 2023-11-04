#include <tamagochi/logic/menu/menu_logic.h>
#include <tamagochi/hardware/buttons/buttons.h>

unsigned short cnt;
void DoMenuLogic(GameConfig *config)
{
    cnt = 0;
    while (ButtonIsReleased(BUTTON_OK))
    {
        PollButtons();
        if (ButtonIsReleased(BUTTON_LEFT))
        {
            cnt = (cnt + 1) % 3;
        }

        if (ButtonIsReleased(BUTTON_RIGHT))
        {
            if (cnt == 0)
            {
                cnt = 2;
            }
            else
            {
                cnt--;
            }
        }
    }
    config->state = ON_GAME;
}