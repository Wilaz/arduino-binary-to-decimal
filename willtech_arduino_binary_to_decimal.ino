/*
 *  Willtech: arduino binary to decimal
 *  
 *  Author: William Zanin
 *  Contact: wbzanin@outlook.com
 *  All Right Reserved
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
const int but_0 = 8;
const int but_1 = 9;
const int but_clear = 10;

// lcd
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
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
  if (digitalRead(8) == HIGH) {
    input = input * 10;
    printscr();
    while (digitalRead(8) == HIGH) {
    delay(1);
    }
  }
  
  if (digitalRead(9) == HIGH){
    input = input * 10 + 1;
    printscr();
    while (digitalRead(9) == HIGH) {
    delay(1);
    }
  }
  
  if (digitalRead(10) == HIGH){
    input = 0;
    printscr();
    while (digitalRead(10) == HIGH) {
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
