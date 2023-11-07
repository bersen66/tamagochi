#include <tamagochi/hardware/lcd/lcd.h>
#include <tamagochi/logic/logic.h>
#include <tamagochi/hardware/hardware.h>
#include <tamagochi/hardware/buttons/buttons.h>


GameConfig cfg;
bit oldstate;

CONNECT_LCD

void main()
{


    InitHardware();
    // InitConfig(&cfg);
    //RunGame(&cfg);
   
    PrintLCD("Aboba");
    //
    // Sleep(1000);
    do
    // duksina@mirea.ru
    {
        //PollButtons();
        if(/*Button(&PORTB, 7, 1, 1)*/ )
        {
            PrintLCD("a");
        }
    } while(1);

    oldstate =  0;
  
//   do {
//     if (Button(&PIND, 0, 1, 1)) {   // Detect logical one
//       oldstate = 1;                 // Update flag
//     }
//     if (oldstate && Button(&PIND, 0, 1, 0)) { // Detect one-to-zero transition
//       PrintLCD("a");               // Invert PORTC
//       oldstate = 0;                 // Update flag
//     }
//   } while(1); 


}