#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define COLS 4
#define ROWS 4

const int pwLen = 4; // Set this to the length of your password
char pw[pwLen];
char apw[] = "2409"; // Set this to your password
int index = 0;

byte colPins[COLS] = {2,3,4,5};
byte rowPins[ROWS] = {6,7,8,9};
char hexaKeys[ROWS][COLS] = {
  {'D','#','0','*'},
  {'C','9','8','7'},
  {'B','6','5','4'},
  {'A','3','2','1'}
};
char button;
Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27, 16, 2); // "0x27" is the HEX address - replace if it doesn't work


void reset() {
  delay(4000);
  index = 0;
  for(int i = 0; i < pwLen; i++) {
    pw[i] = ' ';
  }
  lcd.setCursor(0, 0);
  lcd.print("Enter PIN: ");
  lcd.print("                 ");
  lcd.setCursor(0, 1);
  lcd.print("                 ");
}


void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(10, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Enter PIN: ");
}

void loop() {
  button = keypad.getKey();
  if(button && index < pwLen) {
    pw[index] = button;
    lcd.setCursor(index, 1);
    lcd.print(pw[index]);
    index++;
  }
  if(index == pwLen) {
    int size = strlen(pw);
    pw[size-1] = '\0';
    if(strcmp(pw, apw) == 0) {
      lcd.setCursor(0, 0);
      lcd.print("Correct pin!");
      lcd.setCursor(0, 1);
      lcd.print("Starting PC...");
      digitalWrite(10, HIGH);
      delay(750);
      digitalWrite(10, LOW);
      reset();
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Wrong pin!");
      lcd.setCursor(0, 1);
      lcd.print("           ");
      reset();
    }
  }
}
