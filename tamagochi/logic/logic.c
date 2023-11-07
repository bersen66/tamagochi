#include <tamagochi/logic/logic.h>

#include <tamagochi/logic/menu/menu_logic.h>
#include <tamagochi/logic/gameplay/gameplay_logic.h>

#include <tamagochi/hardware/lcd/lcd.h>

void RunGame(GameConfig *config)
{

    while (1)
    {
        switch (config->state)
        {
        case ON_MENU:
            DoMenuLogic(config);
            break;
        case ON_GAME:
            DoGameplayLogic(config);
            break;
        }
    }
}