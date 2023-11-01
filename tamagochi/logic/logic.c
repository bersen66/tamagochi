#include <tamagochi/logic/logic.h>

void SetupCatLimits(GameConfig *config)
{
    config->type = CAT;
    config->food_lim = 0;
    config->sleep_lim = 0;
    config->love_lim = 0;
    config->wash_lim = 0;
}

void SetupDogLimits(GameConfig *config)
{
    config->type = DOG;
    config->food_lim = 0;
    config->sleep_lim = 0;
    config->love_lim = 0;
    config->wash_lim = 0;
}

void SetupFrogLimits(GameConfig *config)
{
    config->type = FROG;
    config->food_lim = 0;
    config->sleep_lim = 0;
    config->love_lim = 0;
    config->wash_lim = 0;
}

void InitConfig(GameConfig *config)
{
    config->state = ON_MENU;
    config->game_over = false;
    SetupCatLimits(config);
}

typedef struct CurrentParameters
{
    int food;
    int sleep;
    int love;
    int wash;
} Params;

Params params;

void MakeTick(Params *p)
{
    p->food++;
    p->sleep++;
    p->love++;
    p->wash++;
}

void ClearParams(Params *p)
{
    p->food = 0;
    p->sleep = 0;
    p->love = 0;
    p->wash = 0;
}

void RunGame(GameConfig *config)
{

    while (config->game_over)
    {
        switch (config->state)
        {
        case ON_MENU:
            break;
        case ON_GAME:
            MakeTick(&params);
            break;
        }
    }
}