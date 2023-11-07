#include <tamagochi/logic/game_config.h>

void InitConfig(GameConfig *config)
{
    config->state = ON_MENU;
    config->game_over = false;
    config->is_sleeping = false;
    config->is_fat = false;
    SetupCatLimits(config);
}

void SetupCatLimits(GameConfig *config)
{
    config->type = CAT;
    config->food_lim = 0;
    config->sleep_lim = 0;
    config->love_lim = 0;
    config->wash_lim = 0;
}

void SetupMonkeyLimits(GameConfig *config)
{
    config->type = MONKEY;
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