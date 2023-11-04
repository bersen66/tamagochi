#pragma once

#include <tamagochi/logic/game_config.h>

typedef struct CurrentParameters
{
    int food;
    int sleep;
    int love;
    int wash;
} GameplayParameters;

void MakeTick(GameplayParameters *p);

void InitGameplayParameters(GameConfig *cfg, GameplayParameters *p);