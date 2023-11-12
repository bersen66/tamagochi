#include <tamagochi/logic/gameplay/signal_set.h>
#include <tamagochi/hardware/buzzer/buzzer.h>
#include <tamagochi/logic/gameplay/melodies.h>

void InintSignals(SignalSet *signals)
{
    signals->value = 0;
}

SignalLvl ComputeSignalLvl(int limit, int value)
{
    if (value < 0)
        return SIG_CRITICAL;
    if (value < limit / 4)
        return SIG_HIGH;
    if (value < limit / 2)
        return SIG_MEDIUM;
    if (value < limit / 3 * 4)
        return SIG_LOW;

    return SIG_NONE;
}

SignalLvl new;
void UpdateSignals(SignalSet *signals, GameConfig *cfg, GameplayParameters *params)
{
    new = ComputeSignalLvl(cfg->food_lim, params->food);
    if (signals->flags.hunger != new)
    {
        signals->flags.hunger = new;
        cfg->allow_signalization = true;
    }
    new = ComputeSignalLvl(cfg->love_lim, params->love);
    if (signals->flags.love != new)
    {
        signals->flags.love = new;
        cfg->allow_signalization = true;
    }
    new = ComputeSignalLvl(cfg->wash_lim, params->wash);
    if (signals->flags.wash != new)
    {
        signals->flags.wash = new;
        cfg->allow_signalization = true;
    }

    new = ComputeSignalLvl(cfg->sleep_lim, params->sleep);
    if (signals->flags.sleep != new)
    {
        signals->flags.sleep = new;
        cfg->allow_signalization = true;
    }
}

void Hunger(SignalLvl lvl)
{
    switch (lvl)
    {
    case SIG_LOW:
        PLAY_LOW_HUNGER_MELODY;
        break;
    case SIG_MEDIUM:
        PLAY_MEDIUM_HUNGER_MELODY;
        break;
    case SIG_HIGH:
        PLAY_HIGH_HUNGER_MELODY;
        break;
    case SIG_CRITICAL:
        PLAY_CRITICAL_HUNGER_MELODY;
        break;
    default:
        break;
    }
}

void Love(SignalLvl lvl)
{
    switch (lvl)
    {
    case SIG_LOW:
        PLAY_LOW_LOVE_MELODY;
        break;
    case SIG_MEDIUM:
        PLAY_MEDIUM_LOVE_MELODY;
        break;
    case SIG_HIGH:
        PLAY_HIGH_LOVE_MELODY;
        break;
    case SIG_CRITICAL:
        PLAY_CRITICAL_LOVE_MELODY;
        break;
    default:
        break;
    }
}

void Wash(SignalLvl lvl)
{
    switch (lvl)
    {
    case SIG_LOW:
        PLAY_LOW_WASH_MELODY;
        break;
    case SIG_MEDIUM:
        PLAY_MEDIUM_WASH_MELODY;
        break;
    case SIG_HIGH:
        PLAY_HIGH_WASH_MELODY;
        break;
    case SIG_CRITICAL:
        PLAY_CRITICAL_WASH_MELODY;
        break;
    default:
        break;
    }
}

void Sleep(SignalLvl lvl)
{
    switch (lvl)
    {
    case SIG_LOW:
        PLAY_LOW_SLEEP_MELODY;
        break;
    case SIG_MEDIUM:
        PLAY_MEDIUM_SLEEP_MELODY;
        break;
    case SIG_HIGH:
        PLAY_HIGH_SLEEP_MELODY;
        break;
    case SIG_CRITICAL:
        PLAY_CRITICAL_SLEEP_MELODY;
        break;
    default:
        break;
    }
}

void Signalize(SignalSet *signals)
{
    Hunger(signals->flags.hunger);
    Love(signals->flags.love);
    Wash(signals->flags.wash);
    Sleep(signals->flags.sleep);
}
