#include <tamagochi/graphics/graphics.h>
#include <tamagochi/hardware/lcd/lcd.h>
#include <tamagochi/hardware/semisegment/semisegment.h>
#include <tamagochi/graphics/textures.h>


void DoRenderMenuFrame(const char** texture_pack)
{
    ClearLCD();
    PrintLCD(texture_pack[SLIM_BASIC]);
    PrintLCD(texture_pack[MENU_NAME]);
}

void RenderMenuFrame(GameConfig *config)
{
    ClearLCD();
    switch (config->type)
    {
    case CAT:
        DoRenderMenuFrame(CAT_TEXTURES);
        break;
    case MONKEY:
        DoRenderMenuFrame(MONKE_TEXTURES);
        break;
    case FROG:
        DoRenderMenuFrame(FROG_TEXTURES);
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

void RenderAnimalInGameplay(const char **texture_pack, GameConfig *config)
{
    if (config->activity.Sleep)
    {

        if (config->is_fat)
        {
            PrintLCD(texture_pack[FAT_SLEEP]);
        }
        else
        {
            PrintLCD(texture_pack[SLIM_SLEEP]);
        }
        PrintLCD("   Zzzzzzz   ");
    }
    else
    {
        if (config->is_fat)
        {
            PrintLCD(texture_pack[FAT_BASIC]);
        }
        else
        {
            PrintLCD(texture_pack[SLIM_BASIC]);
        }
        PrintLCD(texture_pack[MENU_NAME]);
    }
}

void PrintCat(GameConfig *config)
{
    RenderAnimalInGameplay(CAT_TEXTURES, config);
}

void PrintMonkey(GameConfig *config)
{
    RenderAnimalInGameplay(MONKE_TEXTURES, config);
}

void PrintFrog(GameConfig *config)
{
    RenderAnimalInGameplay(FROG_TEXTURES, config);
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