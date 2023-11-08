#include <tamagochi/hardware/lcd/lcd.h>
#include <tamagochi/logic/logic.h>
#include <tamagochi/hardware/hardware.h>


GameConfig cfg;

CONNECT_LCD

void main()
{
  InitHardware();
  InitConfig(&cfg);
  RunGame(&cfg);
}