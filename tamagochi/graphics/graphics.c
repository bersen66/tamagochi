#include <tamagochi/graphics/graphics.h>
#include <tamagochi/hardware/lcd/lcd.h>
#include <tamagochi/hardware/semisegment/semisegment.h>

/* c(o ") -- frog */
/* =|'W'|= -- cat */
/* @('_')@ -- monkey */

void RenderMenuFrame(GameConfig *config)
{
    ClearLCD();
    switch (config->type)
    {
    case CAT:
        PrintLCD("    =|'W'|=\n");
        PrintLCD("   <-Boris->   ");
        break;
    case MONKEY:
        PrintLCD("    @('_')@\n");
        PrintLCD("   <-Diego->");
        break;
    case FROG:
        PrintLCD("     C(O  )\n");
        PrintLCD("   <-Klava->");
        break;
    }
    PORTA = 0;
}

void DisplayGameOver(char reason[16])
{
    ClearLCD();
    PrintLCD("   GAME OVER.  \n");
    PrintLCD(reason);
}

void PrintCat(GameConfig *config)
{
    if (config->is_sleeping)
    {
        if (config->is_fat)
        {
            PrintLCD("  >|  -W-  |<\n");
        }
        else
        {
            PrintLCD("    >|-W-|<\n");
        }
        PrintLCD("   Zzzzzzzzz  ");
    }
    else
    {
        if (config->is_fat)
        {
            PrintLCD("  =|  ' W '  |=\n");
        }
        else
        {
            PrintLCD("    =|'W'|=\n");
        }
        PrintLCD("     Boris    ");
    }
}

void PrintMonkey(GameConfig *config)
{
    if (config->is_sleeping)
    {
        if (config->is_fat)
        {
            PrintLCD("  @(   -_-   )@\n");
        }
        else
        {
            PrintLCD("    @(-_-)@\n");
        }

        PrintLCD("  Zzzzzzz ");
    }
    else
    {
        if (config->is_fat)
        {
            PrintLCD("  @(   '_'   )@\n");
        }
        else
        {
            PrintLCD("    @('_')@\n");
        }
        PrintLCD("   Diego   ");
    }
}

void PrintFrog(GameConfig *config)
{
    if (config->is_sleeping)
    {

        if (config->is_fat)
        {
            PrintLCD("  -(+     ' )\n");
        }
        else
        {
            PrintLCD("    -(+  ')\n");
        }
        PrintLCD("   Zzzzzzz   ");
    }
    else
    {
        if (config->is_fat)
        {
            PrintLCD("  C(O       ')\n");
        }
        else
        {
            PrintLCD("    C(O ')\n");
        }
        PrintLCD("   Klava   ");
    }
}

void NeedAction(GameConfig *config, GameplayParameters *params)
{
    if (params->food < config->food_lim / 3)
    {
        PrintEatSemisegment();
        return;
    }

    if (params->love < config->love_lim / 3)
    {
        PrintLoveSemisegment();
        return;
    }

    if (params->wash < config->wash_lim / 3)
    {
        PrintBathSemisegment();
        return;
    }

    if (params->sleep < config->sleep_lim / 3)
    {
        PrintRestSemisegment();
        return;
    }

    PrintCoolSemisegment();
}

void RenderGameFrame(GameConfig *config, GameplayParameters *params)
{
    ClearLCD();
    switch (config->type)
    {
    case CAT:
        PrintCat(config);
        break;
    case MONKEY:
        PrintMonkey(config);
        break;
    case FROG:
        PrintFrog(config);
        break;
    }
}