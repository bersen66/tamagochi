#pragma once

#include <tamagochi/utils/bool.h>

typedef enum AppState
{
    ON_MENU = 0,
    ON_GAME = 1,
};

typedef enum AnimalType
{
    CAT = 0,
    MONKEY = 1,
    FROG = 2,
};

typedef struct Config
{
    enum AppState state;
    enum AnimalType type;
    char* game_over_reason;
    
    int food_lim;
    int sleep_lim;
    int love_lim;
    int wash_lim;

    bool game_over;
    bool is_sleeping;
    bool is_fat;
} GameConfig;

void SetupFrogLimits(GameConfig *config);
void SetupCatLimits(GameConfig *config);
void SetupMonkeyLimits(GameConfig *config);

void InitConfig(GameConfig *cfg);