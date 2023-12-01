#pragma once

#include <tamagochi/utils/bool.h>

typedef enum AppState
{
    ON_MENU = 0,
    ON_GAME = 1,
    ON_GAME_OVER = 2,
};

typedef enum AnimalType
{
    CAT = 0,
    MONKEY = 1,
    FROG = 2,
};

typedef struct AnimalActivity
{
    unsigned char Eat : 1;
    unsigned char Love : 1;
    unsigned char Sleep : 1;
    unsigned char Wash : 1;
} AnimalActivity;

typedef struct Config
{
    enum AppState state;
    enum AnimalType type;

    // Flags for determining which activity is currently active
    AnimalActivity activity;

    // used for displaying game over reason
    char *game_over_reason;

    // Stores limits of gameplay parameters
    int food_lim;
    int sleep_lim;
    int love_lim;
    int wash_lim;

    // The amount of each resource that the Tamagochi loses per unit of time.
    int food_dec;
    int sleep_dec;
    int love_dec;
    int wash_dec;

    // The amount of each resource that the Tamagochi gets per unit of time being in activity.
    int food_inc;
    int sleep_inc;
    int love_inc;
    int wash_inc;

    // Used for rendering gameplay parameters
    bool is_game_over;
    bool is_fat;
    bool allow_rerendering;
    bool allow_signalization;
} GameConfig;

// Functions that configure game config for specific animal
void SetupFrogLimits(GameConfig *config);
void SetupCatLimits(GameConfig *config);
void SetupMonkeyLimits(GameConfig *config);

void InitConfig(GameConfig *cfg);

// Clears all activities
void ClearActivities(AnimalActivity *act);