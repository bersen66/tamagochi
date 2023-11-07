#include <tamagochi/logic/menu/menu_logic.h>
#include <tamagochi/hardware/buttons/buttons.h>
#include <tamagochi/graphics/graphics.h>

#include <tamagochi/hardware/time/time.h>
#include <tamagochi/hardware/lcd/lcd.h>

unsigned short cnt;
void DoMenuLogic(GameConfig *config)
{
    
    
    /*
    cnt = 0;
    InitConfig(config);

    RenderMenuFrame(config);
    do
    {
        
        PollButtons();
        
        if (ButtonIsDown(BUTTON_LEFT))
        {
            cnt = (cnt + 1) % 3;
            
        }

        if (ButtonIsReleased(BUTTON_RIGHT))
        {
            if (cnt == 0)
            {
                cnt = 2;
            }
            else
            {
                cnt--;
            }
        }

        if (ButtonIsReleased(BUTTON_MENU))
        {
            cnt = 0;
        }

        switch (cnt)
        {
        case 0:
            SetupCatLimits(config);
            break;
        case 1:
            SetupMonkeyLimits(config);
            break;
        case 2:
            SetupFrogLimits(config);
            break;
        }
    } while (ButtonIsReleased(BUTTON_OK));
    */
   // config->state = ON_GAME;
}