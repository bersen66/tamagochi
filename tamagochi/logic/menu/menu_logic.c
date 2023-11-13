#include <tamagochi/logic/menu/menu_logic.h>
#include <tamagochi/hardware/buttons/buttons.h>
#include <tamagochi/graphics/graphics.h>

#include <tamagochi/hardware/time/time.h>
#include <tamagochi/hardware/lcd/lcd.h>

unsigned short cnt;
unsigned short prev_cnt;
extern ButtonOldstates btns;



void RunMenuLogic(GameConfig *config)
{
    cnt = 0;
    prev_cnt = 0;

    InitConfig(config);
    RenderMenuFrame(config);
    ClearButtonOldstates();

    while (1)
    {
        {
            if (Button(&PINB, 0, 1, 1))
            {
                btns.ok = 1;
            }

            if (Button(&PINB, 1, 1, 1))
            {
                btns.left = 1;
            }

            if (Button(&PINB, 2, 1, 1))
            {
                btns.right = 1;
            }

            if (Button(&PINB, 3, 1, 1))
            {
                btns.menu = 1;
            }

            if (btns.ok && Button(&PINB, 0, 1, 0))
            {
                btns.ok = 0;
                break;
            }

            if (btns.left && Button(&PINB, 1, 1, 0))
            {
                btns.left = 0;
                prev_cnt = cnt;
                if (cnt == 0)
                {
                    cnt = 2;
                }
                else
                {
                    cnt--;
                }
                config->type = cnt;
            }

            if (btns.right && Button(&PINB, 2, 1, 0))
            {
                btns.right = 0;
                prev_cnt = cnt;
                cnt = (cnt + 1) % 3;
                config->type = cnt;
            }

            if (btns.menu && Button(&PINB, 3, 1, 0))
            {
                btns.menu = 0;
                prev_cnt = cnt;
                cnt = 0;
                config->type = cnt;
            }
        }

        if (prev_cnt != cnt)
        {
            switch (cnt)
            {
            case CAT:
                SetupCatLimits(config);
                break;
            case MONKEY:
                SetupMonkeyLimits(config);
                break;
            case FROG:
                SetupFrogLimits(config);
                break;
            }
            RenderMenuFrame(config);
        }

        prev_cnt = cnt;
    }

    config->state = ON_GAME;
}