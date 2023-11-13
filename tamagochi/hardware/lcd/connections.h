#pragma once

/**
 * @brief Defines the connections of the LCD to the microcontroller.
 * 
 * This macro defines the specific pins of the microcontroller that are connected to the LCD display.
 * It uses the sbit keyword to define each pin as a bit of a specific port, and also defines the direction
 * of each pin using the sbit keyword and the _Direction suffix.
 * 
 * Usage: 
 *  - Include this header file in the source file where the LCD is used.
 *  - Call the macro CONNECT_LCD before initializing the LCD.
 */
#ifndef CONNECT_LCD
#define CONNECT_LCD \
sbit LCD_RS at PORTA2_bit; \
sbit LCD_EN at PORTD6_bit; \
sbit LCD_D4 at PORTC4_bit; \
sbit LCD_D5 at PORTC5_bit; \
sbit LCD_D6 at PORTC6_bit; \
sbit LCD_D7 at PORTC7_bit; \
sbit LCD_RS_Direction at DDA2_bit; \
sbit LCD_EN_Direction at DDD6_bit; \
sbit LCD_D4_Direction at DDC4_bit; \
sbit LCD_D5_Direction at DDC5_bit; \
sbit LCD_D6_Direction at DDC6_bit; \
sbit LCD_D7_Direction at DDC7_bit;
#endif // CONNECT_LCD