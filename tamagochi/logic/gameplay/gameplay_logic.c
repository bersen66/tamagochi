#include <tamagochi/hardware/buttons/buttons.h>

#include <tamagochi/logic/gameplay/gameplay_logic.h>
#include <tamagochi/logic/game_config.h>
#include <tamagochi/logic/gameplay/gameplay_parameters.h>
#include <tamagochi/graphics/graphics.h>

GameplayParameters params;

bool HasGameOverSituation(GameConfig *config, GameplayParameters *parameters)
{
    if (params.food <= 0)
    {
        config->game_over = true;
        config->game_over_reason = "Hunger";
    }
    else if (params.love <= 0)
    {
        config->game_over = true;
        config->game_over_reason = "Loneliness";
    }
    else if (params.wash <= 0)
    {
        config->game_over = true;
        config->game_over_reason = "Dirt";
    }
    else if (params.sleep <= 0)
    {
        config->game_over = true;
        config->game_over_reason = "Sleepiness";
    }

    return config->game_over;
}

void DoGameplayLogic(GameConfig *config)
{
    InitGameplayParameters(config, &params);
    // Main logic loop
    do
    {
        
        MakeTick(&params);

        PollButtons();

        if (ButtonIsReleased(BUTTON_MENU))
        {
            config->game_over = true;
            break;
        }
        
        if (ButtonIsReleased(BUTTON_SLEEP))
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
    } while (HasGameOverSituation(config, &params));

    // Game over screen
    DisplayGameOver(config->game_over_reason);
    do
    {
        PollButtons();
    } while (ButtonIsReleased(BUTTON_MENU) || ButtonIsReleased(BUTTON_OK));

    config->state = ON_MENU;
}