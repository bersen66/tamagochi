#include <tamagochi/hardware/lcd/functions.h>
#include <string.h>

struct LCDScreen
{
    int curr;
} screen;

#define WD 16
#define HG 2

static int i = 0;
static int n = 0;

void InitLCD()
{
    Lcd_Init();
    Lcd_Cmd(_LCD_CURSOR_OFF);
    ClearLCD();
}

void ClearLCD()
{
    Lcd_Cmd(_LCD_CLEAR);
    screen.curr = 0;
}

void DoShift(char direction, int offset, dur_t timeout)
{
    for (i = 0; i < offset; i++)
    {
        Lcd_Cmd(direction);
        Sleep(timeout);
    }
}

void ShiftLeftLCD(int offset, dur_t timeout)
{
    DoShift(_LCD_SHIFT_LEFT, offset, timeout);
}

void ShiftRightLCD(int offset, dur_t timeout)
{
    DoShift(_LCD_SHIFT_RIGHT, offset, timeout);
}

inline char GetRow(char idx)
{
    return idx / WD + 1;
}

inline char GetCol(char idx)
{
    return idx % WD + 1;
}

// TODO: printf analogue 
void PrintLCD(char *text)
{
    while (*text != '\0')
    {
        if (screen.curr >= WD * HG)
        {
            ClearLCD();
        }
        if (*text == '\t')
        {
            screen.curr += 4;
            for (i = 0; i < 4; i++)
            {
                Lcd_Chr(GetRow(screen.curr), GetCol(screen.curr), ' ');
            }
        }
        else if (*text == '\n')
        {
            screen.curr += (WD - (screen.curr % WD));
        }
        else
        {
            Lcd_Chr(GetRow(screen.curr), GetCol(screen.curr), *text);
            screen.curr++;
        }
        text++;
    }
}