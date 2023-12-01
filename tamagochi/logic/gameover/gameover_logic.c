#include <tamagochi/logic/gameover/gameover_logic.h>
#include <tamagochi/graphics/graphics.h>
#include <tamagochi/hardware/buttons/buttons.h>

#include <tamagochi/hardware/time/time.h>

void RunGameoverLogic(GameConfig *config)
{
    ClearButtonOldstates();
    DisplayGameOver(config->game_over_reason);
    while (1)
    {
       
        if (Button(&PINB, 0, 1, 1))
        {
            btns.ok = 1;
        }

        if (Button(&PINB, 3, 1, 1))
        {
            btns.menu = 1;
        }
        ///////////////////////////////////////////////////////////////////
        if (btns.ok && Button(&PINB, 0, 1, 0))
        {
            btns.ok = 0;
            break;
        }

        if (btns.menu && Button(&PINB, 3, 1, 0))
        {
            btns.menu = 0;
            break;
        }
       
    }

    config->state = ON_MENU;
}