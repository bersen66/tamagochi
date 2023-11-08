#include <tamagochi/hardware/buttons/buttons.h>

#include <tamagochi/logic/gameplay/gameplay_logic.h>
#include <tamagochi/logic/game_config.h>
#include <tamagochi/logic/gameplay/gameplay_parameters.h>
#include <tamagochi/graphics/graphics.h>
#include <tamagochi/hardware/time/time.h>

GameplayParameters params;
extern ButtonOldstates btns;

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

typedef struct AnimalActivity
{
    unsigned short Eat : 1;
    unsigned short Pet : 1;
    unsigned short Sleep : 1;
    unsigned short Wash : 1;
} AnimalActivity;

AnimalActivity activity;

void ClearActivities(AnimalActivity *act)
{
    act->Eat = 0;
    act->Pet = 0;
    act->Sleep = 0;
    act->Wash = 0;
}

void DoGameplayLogic(GameConfig *config)
{
    InitGameplayParameters(config, &params);
    ClearButtonOldstates();
    ClearActivities(&activity);

    RenderGameFrame(config, &params);
    while (!HasGameOverSituation(config, &params))
    {
        MakeTick(&params);

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
            ///////////////////////////////////////////////////////////////////
            if (btns.feed && Button(&PIND, 0, 1, 0))
            {
                btns.feed = 0;
                if (activity.Pet == 0 && activity.Sleep == 0 && activity.Wash == 0)
                {
                    activity.Eat = !activity.Eat;
                }
            }

            if (btns.love && Button(&PIND, 1, 1, 0))
            {
                btns.love = 0;
                if (activity.Eat == 0 && activity.Sleep == 0 && activity.Wash == 0)
                {
                    activity.Pet = !activity.Pet;
                }
            }

            if (btns.wash && Button(&PIND, 2, 1, 0))
            {
                btns.wash = 0;
                if (activity.Eat == 0 && activity.Pet == 0 && activity.Sleep == 0)
                {
                    activity.Wash = !activity.Wash;
                }
            }

            if (btns.sleep && Button(&PIND, 3, 1, 0))
            {
                btns.sleep = 0;
                if (activity.Eat == 0 && activity.Pet == 0 && activity.Wash == 0)
                {
                    activity.Sleep = !activity.Sleep;
                    if (activity.Sleep == 0)
                    {
                        config->is_sleeping = false;
                    }
                    else
                    {
                        config->is_sleeping = true;
                    }
                }
            }

            if (btns.menu && Button(&PINB, 3, 1, 0))
            {
                btns.menu = 0;
                config->game_over_reason = "U pressed menu";
                config->game_over = true;
                break;
            }
        }

        if (activity.Eat)
        {
            PrintEatSemisegment();
            params.food += 30;
        }
        else if (activity.Pet)
        {
            PrintLoveSemisegment();
            params.love += 30;
        }
        else if (activity.Sleep)
        {
            PrintRestSemisegment();
            params.sleep += 30;
        }
        else if (activity.Wash)
        {
            PrintBathSemisegment();
            params.wash += 30;
        }

        
        if (params.food > config->food_lim)
        {
            config->is_fat = true;
        }
        else
        {
            config->is_fat = false;
        }


        RenderGameFrame(config, &params);
        Sleep(300 * MILLISECOND);
    }

    DisplayGameOver(config->game_over_reason);
    while (1)
    {
        if (Button(&PINB, 0, 1, 1))
        {
            btns.ok = 1;
        }

        if (Button(&PINB, 3, 1, 0))
        {
            btns.ok = 0;
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