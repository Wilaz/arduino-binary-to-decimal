/*
 *  Arduino - binary to decimal
 *  Copyright (C) 2022  William Zanin
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *  
 *  credits for binary to decimal: Bansal , Sunidhi. Program for Binary to Decimal Conversion in C++, https://www.tutorialspoint.com/program-for-binary-to-decimal-conversion-in-cplusplus. 
 */

#include <LiquidCrystal.h>
#include <math.h>


// main variabils
double input = 0;
int cins;
void printscr();
int convert(long long);

// buttons
const int but_0 = 11;
const int but_1 = 12;
const int but_clear = 13;

// lcd
const int rs = 0, en = 1, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
 // setups buttons
  pinMode(but_0, INPUT);
  pinMode(but_1, INPUT);
  pinMode(but_clear, INPUT);

  // inits lcd
  lcd.begin(16, 2);
  lcd.clear();
  printscr();
}


void loop() {
  // checks inputs and prints
  if (digitalRead(but_0) == HIGH) {
    input = input * 10;
    printscr();
    while (digitalRead(but_0) == HIGH) {
    delay(1);
    }
  }
  
  if (digitalRead(but_1) == HIGH){
    input = input * 10 + 1;
    printscr();
    while (digitalRead(but_1) == HIGH) {
    delay(1);
    }
  }
  
  if (digitalRead(but_clear) == HIGH){
    input = 0;
    printscr();
    while (digitalRead(but_clear) == HIGH) {
    delay(1);
    }
  }

  // delays to increase performance
  delay(10);
}


// prints current input and answer
void printscr(){
  lcd.clear();

  // prints user inputs
  lcd.setCursor(0, 0);
    lcd.print(input);

  // prints user input in decimal
  lcd.setCursor(0, 1);
    lcd.print(convert(input));
}


// converts binary to decimal
int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}
