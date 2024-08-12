#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>


const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '7', '8', '9', 'C' },
  { '4', '5', '6', 'B' },
  { '*', '0', '#', 'D' }
};

// Connections to Arduino
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };

// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Create LCD object
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Setup LCD with backlight and initialize
  lcd.backlight();
  lcd.init();
  lcd.setCursor(1, 0);
  lcd.print("Enter Password");
  Serial.begin(9600);
}

// define vars
String pin = "";
String correctPin = "1121";
bool currentlyUnlocked = false;

void loop() {
  // Get key value if pressed
  char customKey = customKeypad.getKey();

  if (customKey) {

    if (isdigit(customKey)) {
      pin += String(customKey);
      lcd.clear();
      lcd.setCursor(0, 0);
      if (pin.length() >= 17) {
        lcd.print(pin.substring(pin.length() - 16));
        printCClear();
      } else {
        lcd.print(pin);
        printCClear();
      };
      Serial.println(pin);
    } else {
      switch (customKey) {
        case 'A':
          if (currentlyUnlocked) {
            lockDoor();
          };
          break;
        case 'C':
          if (!currentlyUnlocked) {
            clearPin();
          };
          break;
        case '*':
          validatePin();
          break;
        case '#':
          validatePin();
          break;
        default:
          break;
      };
    };
  };
}

void printCClear() {
  lcd.setCursor(0, 1);
  lcd.print("Press C to clear");
};
void clearPin() {
  pin = "";
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Cleared!");
  lcd.setCursor(1, 1);
  lcd.print("Enter Password");
};
void validatePin() {
  lcd.clear();
  if (pin == correctPin) {
    currentlyUnlocked = true;
    lcd.setCursor(1, 0);
    lcd.print("Door unlocked!");
    lcd.setCursor(0, 1);
    lcd.print("Press A to lock.");
    pin = "";

  } else {
    lcd.setCursor(1, 0);
    lcd.print("Incorrect Pin!");
    lcd.setCursor(1, 1);
    lcd.print("Enter Password");
    pin = "";
  };
};

void lockDoor() {
  if (!currentlyUnlocked) { return; };
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Enter Password");
  currentlyUnlocked = false;
};