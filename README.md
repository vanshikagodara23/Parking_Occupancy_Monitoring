# Parking Occupancy Monitoring

Parking occupancy monitor for 3 parking spots using IR sensors, RGB LEDs and a 16x2 I2C LCD on an ESP32.

## How it works

- Each parking spot has one IR sensor and one RGB LED.
- **Red** LED = spot occupied, **Green** LED = spot free.
- The LCD shows each spot's status on line 1 (`X` = occupied, `O` = open), for example `1:X 2:O 3:O`.
- Line 2 shows the number of free spaces, for example `Free Spaces: 2`.
- The display updates every 0.3 seconds.

## Components

- ESP32 development board
- 3 × IR obstacle sensors
- 3 × RGB LEDs + resistors (220 Ω)
- 16x2 LCD with I2C module
- Jumper wires, breadboard

## Wiring

| Part | Pin | ESP32 pin |
|---|---|---|
| IR sensor 1 | OUT | 14 |
| IR sensor 2 | OUT | 27 |
| IR sensor 3 | OUT | 26 |
| LED 1 | Red / Green | 13 / 12 |
| LED 2 | Red / Green | 33 / 32 |
| LED 3 | Red / Green | 4 / 25 |
| I2C LCD | SDA | 21 |
| I2C LCD | SCL | 22 |

## Libraries

- LiquidCrystal_I2C

## How to run

1. Install the **LiquidCrystal_I2C** library from the Library Manager.
2. Select an ESP32 board in the Arduino IDE.
3. If the LCD stays blank, change the address `0x27` in the code to `0x3F`.
4. Upload to the board.
