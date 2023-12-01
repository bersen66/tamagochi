#include <tamagochi/hardware/buttons/buttons.h>

#include <tamagochi/logic/gameplay/gameplay_logic.h>
#include <tamagochi/logic/game_config.h>
#include <tamagochi/logic/gameplay/gameplay_parameters.h>
#include <tamagochi/graphics/graphics.h>
#include <tamagochi/hardware/time/time.h>
#include <tamagochi/logic/gameplay/signal_set.h>

GameplayParameters params;
SignalSet signals;

/**
 * Determines if the game has reached a game over situation based on the given parameters.
 * If any of the parameters (food, love, wash, sleep) are less than or equal to 0, the game is over.
 * @param config The game configuration.
 * @param parameters The gameplay parameters.
 * @return True if the game is over, false otherwise.
 */
bool HasGameOverSituation(GameConfig *config, GameplayParameters *parameters)
{
    if (params.food <= 0)
    {
        config->is_game_over = true;
        config->game_over_reason = "     Hunger    ";
    }
    else if (params.love <= 0)
    {
        config->is_game_over = true;
        config->game_over_reason = "   Loneliness  ";
    }
    else if (params.wash <= 0)
    {
        config->is_game_over = true;
        config->game_over_reason = "     Dirt      ";
    }
    else if (params.sleep <= 0)
    {
        config->is_game_over = true;
        config->game_over_reason = "   Sleepiness  ";
    }

    return config->is_game_over;
}

void PollButtons(GameConfig *config, GameplayParameters *params)
{
    if (Button(&PIND, 0, 1, 1))
    {
        btns.feed = 1;
    }

    if (Button(&PIND, 1, 1, 1))
    {
        btns.love = 1;
    }

    if (Button(&PIND, 2, 1, 1))
    {
        btns.wash = 1;
    }

    if (Button(&PIND, 3, 1, 1))
    {
        btns.sleep = 1;
    }

    if (Button(&PINB, 3, 1, 1))
    {
        btns.menu = 1;
    }

    if (btns.feed && Button(&PIND, 0, 1, 0))
    {
        btns.feed = 0;
        if (config->activity.Love == 0 && config->activity.Sleep == 0 && config->activity.Wash == 0)
        {
            config->activity.Eat = !config->activity.Eat;
            config->allow_rerendering = true;
        }
    }

    if (btns.love && Button(&PIND, 1, 1, 0))
    {
        btns.love = 0;
        if (config->activity.Eat == 0 && config->activity.Sleep == 0 && config->activity.Wash == 0)
        {
            config->activity.Love = !config->activity.Love;
            config->allow_rerendering = true;
        }
    }

    if (btns.wash && Button(&PIND, 2, 1, 0))
    {
        btns.wash = 0;
        if (config->activity.Eat == 0 && config->activity.Love == 0 && config->activity.Sleep == 0)
        {
            config->activity.Wash = !config->activity.Wash;
            config->allow_rerendering = true;
        }
    }

    if (btns.sleep && Button(&PIND, 3, 1, 0))
    {
        btns.sleep = 0;
        if (config->activity.Eat == 0 && config->activity.Love == 0 && config->activity.Wash == 0)
        {
            config->activity.Sleep = !config->activity.Sleep;
            config->allow_rerendering = true;
        }
    }

    if (btns.menu && Button(&PINB, 3, 1, 0))
    {
        btns.menu = 0;
        config->game_over_reason = " U pressed menu";
        config->is_game_over = true;
    }
}

void UpdateFatness(GameConfig *config, GameplayParameters *params)
{
    if (!config->is_fat && params->food > config->food_lim)
    {
        config->is_fat = true;
        config->allow_rerendering = true;
    }
    if (config->is_fat && params->food < config->food_lim)
    {
        config->is_fat = false;
        config->allow_rerendering = true;
    }
}

/**
 * @brief Updates the logic of the gameplay.
 *
 * @param config Pointer to the game configuration.
 * @param params Pointer to the gameplay parameters.
 */
void UpdateLogic(GameConfig *config, GameplayParameters *params)
{
    UpdateGameplayParameters(config, params);
    UpdateFatness(config, params);
}

void RunGameplayLogic(GameConfig *config)
{
    InitGameplayParameters(config, &params);
    InintSignals(&signals);

    ClearButtonOldstates();

    RenderGameFrame(config, &params);

    do
    {
        PollButtons(config, &params);
        if (config->is_game_over)
        {
            break;
        }
        UpdateLogic(config, &params);

        if (config->allow_rerendering)
        {
            RenderGameFrame(config, &params);
            config->allow_rerendering = false;
        }

        UpdateSignals(&signals, config, &params);
        if (config->allow_signalization)
        {
            Signalize(&signals);
            config->allow_signalization = false;
        }
        Sleep(50 * MILLISECOND);
    } while (!HasGameOverSituation(config, &params));

    config->state = ON_GAME_OVER;
}