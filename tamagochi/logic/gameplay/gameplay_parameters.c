#include <tamagochi/logic/gameplay/gameplay_parameters.h>

int limitate(int curr, int lim)
{
    if (curr > lim)
    {
        return lim;
    }
    else
    {
        return curr;
    }
}

void UpdateGameplayParameters(GameConfig *config, GameplayParameters *p)
{
    p->food = p->food - config->food_dec + (config->activity.Eat * config->food_inc);
    p->sleep = p->sleep - config->sleep_dec + (config->activity.Sleep * config->sleep_inc);
    p->love = p->love - config->love_dec + (config->activity.Love * config->love_inc);
    p->wash = p->wash - config->wash_dec + (config->activity.Wash * config->wash_inc);

    p->food = limitate(p->food, config->food_lim);
    p->sleep = limitate(p->sleep, config->sleep_lim);
    p->love = limitate(p->love, config->love_lim);
    p->wash = limitate(p->wash, config->wash_lim);
}

void InitGameplayParameters(GameConfig *cfg, GameplayParameters *p)
{
    p->food = cfg->food_lim;
    p->sleep = cfg->sleep_lim;
    p->love = cfg->love_lim;
    p->wash = cfg->wash_lim;

    ClearActivities(&(cfg->activity));
}