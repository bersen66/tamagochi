#pragma once

#include <tamagochi/utils/bool.h>

typedef enum GameState
{
    ON_MENU = 0,
    ON_GAME = 1,
};

typedef enum AnimalType
{
    CAT = 0,
    DOG = 1,
    FROG = 2,
};

typedef struct Config
{
    enum GameState state;
    enum AnimalType type;
    int food_lim;
    int sleep_lim;
    int love_lim;
    int wash_lim;
    bool game_over;
    bool is_sleeping;
} GameConfig;

void SetupFrogLimits(GameConfig *config);
void SetupCatLimits(GameConfig *config);
void SetupDogLimits(GameConfig *config);

void InitConfig(GameConfig *cfg);