// Aim: Parking occupancy monitoring

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions for IR Sensors
#define IR_PIN_1      14
#define IR_PIN_2      27
#define IR_PIN_3      26

// Pin Definitions for RGB LEDs (Red and Green pins only)
#define RED_LED_1     13
#define GREEN_LED_1   12

#define RED_LED_2     33
#define GREEN_LED_2   32

#define RED_LED_3     4
#define GREEN_LED_3   25

void setup() {
  Serial.begin(115200);

  // Initialize IR Pins
  pinMode(IR_PIN_1, INPUT);
  pinMode(IR_PIN_2, INPUT);
  pinMode(IR_PIN_3, INPUT);

  // Initialize RGB LED Pins
  pinMode(RED_LED_1, OUTPUT);
  pinMode(GREEN_LED_1, OUTPUT);
  pinMode(RED_LED_2, OUTPUT);
  pinMode(GREEN_LED_2, OUTPUT);
  pinMode(RED_LED_3, OUTPUT);
  pinMode(GREEN_LED_3, OUTPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Startup Message
  lcd.setCursor(0, 0);
  lcd.print("RGB Parking Sys");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read all IR sensors (LOW = Car Detected / Full, HIGH = Clear / Available)
  int spot1 = digitalRead(IR_PIN_1);
  int spot2 = digitalRead(IR_PIN_2);
  int spot3 = digitalRead(IR_PIN_3);

  // Control RGB LED 1 (Spot 1)
  if (spot1 == LOW) {
    digitalWrite(RED_LED_1, HIGH);   // Turn Red ON
    digitalWrite(GREEN_LED_1, LOW);  // Turn Green OFF
  } else {
    digitalWrite(RED_LED_1, LOW);    // Turn Red OFF
    digitalWrite(GREEN_LED_1, HIGH); // Turn Green ON
  }

  // Control RGB LED 2 (Spot 2)
  if (spot2 == LOW) {
    digitalWrite(RED_LED_2, HIGH);
    digitalWrite(GREEN_LED_2, LOW);
  } else {
    digitalWrite(RED_LED_2, LOW);
    digitalWrite(GREEN_LED_2, HIGH);
  }

  // Control RGB LED 3 (Spot 3)
  if (spot3 == LOW) {
    digitalWrite(RED_LED_3, HIGH);
    digitalWrite(GREEN_LED_3, LOW);
  } else {
    digitalWrite(RED_LED_3, LOW);
    digitalWrite(GREEN_LED_3, HIGH);
  }

  // Update LCD Display
  lcd.setCursor(0, 0);
  lcd.print("1:");
  lcd.print(spot1 == LOW ? "X" : "O"); // X = Occupied, O = Open
  lcd.print(" 2:");
  lcd.print(spot2 == LOW ? "X" : "O");
  lcd.print(" 3:");
  lcd.print(spot3 == LOW ? "X" : "O");

  // Row 2: Count available spaces
  int availableCount = 0;
  if (spot1 == HIGH) availableCount++;
  if (spot2 == HIGH) availableCount++;
  if (spot3 == HIGH) availableCount++;

  lcd.setCursor(0, 1);
  lcd.print("Free Spaces: ");
  lcd.print(availableCount);
  lcd.print(" ");

  delay(300);
}
