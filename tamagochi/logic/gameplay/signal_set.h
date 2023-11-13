#pragma once

#include <tamagochi/logic/game_config.h>
#include <tamagochi/logic/gameplay/gameplay_parameters.h>

typedef enum SignalLvl
{
    SIG_NONE = 0,
    SIG_LOW = 1,
    SIG_MEDIUM = 2,
    SIG_HIGH = 3,
    SIG_CRITICAL = 4,
} SignalLvl;

typedef struct SignalFlags
{
    unsigned short hunger : 3;
    unsigned short love : 3;
    unsigned short wash : 3;
    unsigned short sleep : 3;
} SignalFlags;

typedef union SignalSet
{
    SignalFlags flags;
    unsigned short value;
} SignalSet;

extern SignalSet SIGNALS;

void InintSignals(SignalSet *signals);

void UpdateSignals(SignalSet* signals, GameConfig* cfg, GameplayParameters *params);

void Signalize(SignalSet* signals);