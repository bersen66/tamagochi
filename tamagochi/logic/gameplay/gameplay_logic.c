#include <tamagochi/logic/gameplay/gameplay_logic.h>
#include <tamagochi/hardware/buttons/buttons.h>
#include <tamagochi/logic/game_config.h>
#include <tamagochi/logic/gameplay/gameplay_parameters.h>

GameplayParameters params;

void DoGameplayLogic(GameConfig *config)
{
    InitGameplayParameters(config, &params);
    while (config->game_over)
    {

        MakeTick(&params);
        PollButtons();
        if (ButtonIsPressed(BUTTON_MENU))
        {
            config->game_over = true;
            break;
        }
        if (ButtonIsPressed(BUTTON_SLEEP))
        {
            config->is_sleeping = !config->is_sleeping;
        }

        if (!config->is_sleeping)
        {
            if (ButtonIsDown(BUTTON_LOVE))
            {
                params.love += 10;
            }

            if (ButtonIsDown(BUTTON_FEED))
            {
                params.food += 2;
            }
            if (ButtonIsDown(BUTTON_WASH))
            {
                params.wash += 5;
            }
        }
        
    }
    config->state = ON_MENU;
}