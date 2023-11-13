#include <tamagochi/logic/logic.h>

#include <tamagochi/logic/menu/menu_logic.h>
#include <tamagochi/logic/gameplay/gameplay_logic.h>
#include <tamagochi/logic/gameover/gameover_logic.h>

void RunGame(GameConfig *config)
{
    while (1)
    {
        switch (config->state)
        {
        case ON_MENU:
            RunMenuLogic(config);
            break;
        case ON_GAME:
            RunGameplayLogic(config);
            break;
        case ON_GAME_OVER:
            RunGameoverLogic(config);
            break;    
        }
    }
}