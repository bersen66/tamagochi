#include <tamagochi/hardware/semisegment/semisegment.h>

unsigned short shifter, portd_index;
unsigned short portd_array[4] = {0, 0, 0, 0};

void InitSemisegments()
{   
    portd_index = 0;
    shifter = 1;
}

unsigned short MaksOf(char c)
{
    switch (c)
    {
    case 'O':
    case '0':
        return 0x3F;
    case '1':
        return 0x06;
    case '2':
        return 0x5B;
    case '3':
        return 0x4F;
    case '4':
        return 0x66;
    case '5':
        return 0x6D;
    case '6':
        return 0x7D;
    case '7':
        return 0x07;
    case '8':
        return 0x7F;
    case '9':
        return 0x6F;

    case 'E':
    case 'e':
        return 0x79;
    case 'A':
    case 'a':
        return 0x77;
    case 'T':
    case 't':
        return 0x78;

    case 'L':
    case 'l':
        return 0x38;
    case 'o':
        return 0x5C;
    case 'V':
    case 'v':
        return 0x3E;
    case 'b':
    case 'B':
        return 0x7C;
    case 'h':
    case 'H':
        return 0x74;
    case 'r':
    case 'R':
        return 0x50;
    case 'S':
    case 's':
        return 0x6D;
    case 'C':
    case 'c':
        return 0x39;
    default:
        return 0x00;
    }
}

void Flush()
{
    PORTA = 0;                        // Turn off all 7seg displays
    PORTC = portd_array[portd_index]; // bring appropriate value to PORTC
    PORTA = shifter;                  // turn on appropriate 7seg. display

    //move shifter to next digit
    shifter <<= 1;
    if (shifter > 8u)
        shifter = 1;

    // increment portd_index
    portd_index++;
    if (portd_index > 3u)
        portd_index = 0; // turn on 1st, turn off 2nd 7seg.
}

void PrintEatSemisegment()
{
    portd_array[3] = MaksOf('E');
    portd_array[2] = MaksOf('A');
    portd_array[1] = MaksOf('T');
    portd_array[0] = MaksOf(' ');
}

void PrintRestSemisegment()
{
    portd_array[3] = MaksOf('R');
    portd_array[2] = MaksOf('E');
    portd_array[1] = MaksOf('S');
    portd_array[0] = MaksOf('T');
}

void PrintLoveSemisegment()
{
    portd_array[3] = MaksOf('L');
    portd_array[2] = MaksOf('O');
    portd_array[1] = MaksOf('V');
    portd_array[0] = MaksOf('E');
}

void PrintBathSemisegment()
{
    portd_array[3] = MaksOf('B');
    portd_array[2] = MaksOf('A');
    portd_array[1] = MaksOf('T');
    portd_array[0] = MaksOf('H');
}

void PrintCoolSemisegment() 
{
    portd_array[3] = MaksOf('C');
    portd_array[2] = MaksOf('O');
    portd_array[1] = MaksOf('O');
    portd_array[0] = MaksOf('L');
}

void ClearSemisegment()
{
    portd_array[3] = MaksOf(' ');
    portd_array[2] = MaksOf(' ');
    portd_array[1] = MaksOf(' ');
    portd_array[0] = MaksOf(' ');  
}