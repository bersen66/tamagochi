#pragma once

#include <tamagochi/hardware/buzzer/buzzer.h>

#ifndef PLAY_CRITICAL_HUNGER_MELODY
#define PLAY_CRITICAL_HUNGER_MELODY    \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_CRITICAL_HUNGER_MELODY

#ifndef PLAY_HIGH_HUNGER_MELODY
#define PLAY_HIGH_HUNGER_MELODY        \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_HIGH_HUNGER_MELODY

#ifndef PLAY_MEDIUM_HUNGER_MELODY
#define PLAY_MEDIUM_HUNGER_MELODY      \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_MEDIUM_HUNGER_MELODY

#ifndef PLAY_LOW_HUNGER_MELODY
#define PLAY_LOW_HUNGER_MELODY         \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_LOW_HUNGER_MELODY

#ifndef PLAY_CRITICAL_LOVE_MELODY
#define PLAY_CRITICAL_LOVE_MELODY      \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_CRITICAL_LOVE_MELODY

#ifndef PLAY_HIGH_LOVE_MELODY
#define PLAY_HIGH_LOVE_MELODY          \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_HIGH_LOVE_MELODY

#ifndef PLAY_MEDIUM_LOVE_MELODY
#define PLAY_MEDIUM_LOVE_MELODY        \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_MEDIUM_LOVE_MELODY

#ifndef PLAY_LOW_LOVE_MELODY
#define PLAY_LOW_LOVE_MELODY           \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_LOW_LOVE_MELODY

#ifndef PLAY_CRITICAL_SLEEP_MELODY
#define PLAY_CRITICAL_SLEEP_MELODY     \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_CRITICAL_SLEEP_MELODY

#ifndef PLAY_HIGH_SLEEP_MELODY
#define PLAY_HIGH_SLEEP_MELODY         \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_HIGH_SLEEP_MELODY

#ifndef PLAY_MEDIUM_SLEEP_MELODY
#define PLAY_MEDIUM_SLEEP_MELODY       \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_MEDIUM_SLEEP_MELODY

#ifndef PLAY_LOW_SLEEP_MELODY
#define PLAY_LOW_SLEEP_MELODY          \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_LOW_SLEEP_MELODY

#ifndef PLAY_CRITICAL_WASH_MELODY
#define PLAY_CRITICAL_WASH_MELODY      \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_CRITICAL_WASH_MELODY

#ifndef PLAY_HIGH_WASH_MELODY
#define PLAY_HIGH_WASH_MELODY          \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_HIGH_WASH_MELODY

#ifndef PLAY_MEDIUM_WASH_MELODY
#define PLAY_MEDIUM_WASH_MELODY        \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_MEDIUM_WASH_MELODY

#ifndef PLAY_LOW_WASH_MELODY
#define PLAY_LOW_WASH_MELODY           \
    {                                  \
        Beep(1000, 100 * MILLISECOND); \
    }
#endif // PLAY_LOW_WASH_MELODY
