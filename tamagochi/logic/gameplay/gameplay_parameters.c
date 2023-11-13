#include <tamagochi/logic/gameplay/gameplay_parameters.h>

void UpdateGameplayParameters(GameConfig *config, GameplayParameters *p)
{
    p->food  = p->food  - config->food_dec   + (config->activity.Eat   * config->food_inc);
    p->sleep = p->sleep - config->sleep_dec  + (config->activity.Sleep * config->sleep_inc);
    p->love  = p->love  - config->love_dec   + (config->activity.Love  * config->love_inc);
    p->wash  = p->wash  - config->wash_dec   + (config->activity.Wash  * config->wash_inc);  
}

void InitGameplayParameters(GameConfig *cfg, GameplayParameters *p)
{
    p->food = cfg->food_lim;
    p->sleep = cfg->sleep_lim;
    p->love = cfg->love_lim;
    p->wash = cfg->wash_lim;

    ClearActivities(&(cfg->activity));
}