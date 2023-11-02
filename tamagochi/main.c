#include <tamagochi/hardware/hardware.h>
#include <tamagochi/logic/logic.h>

GameConfig cfg;

void main()
{
    InitHardware();
    InitConfig(&cfg);
    RunGame(&cfg);
}