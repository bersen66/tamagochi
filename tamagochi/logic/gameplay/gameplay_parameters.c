#include <tamagochi/logic/gameplay/gameplay_parameters.h>

void MakeTick(GameplayParameters *p)
{
    p->food--;
    p->sleep--;
    p->love--;
    p->wash--;
}

void InitGameplayParameters(GameConfig *cfg, GameplayParameters *p)
{
    p->food = cfg->food_lim;
    p->sleep = cfg->sleep_lim;
    p->love = cfg->love_lim;
    p->wash = cfg->wash_lim;
}