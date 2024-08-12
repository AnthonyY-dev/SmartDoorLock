# SmartDoorLock

**SmartDoorLock** is an Arduino-based security system using a 4x4 matrix keypad and an LCD display. It requires a 4-digit PIN to unlock the door and provides real-time feedback through the LCD.

## Features

- 4-digit PIN protection
- Real-time feedback on the LCD
- PIN reset and manual locking

## Components

- Arduino Uno (or compatible)
- 4x4 Matrix Keypad
- 16x2 LCD with I2C
- Jumper wires and breadboard

## Circuit

- **LCD**: `VCC` to `5V`, `GND` to `GND`, `SDA` to `A4`, `SCL` to `A5`
- **Keypad**: Rows to pins `9, 8, 7, 6`, Columns to pins `5, 4, 3, 2`

## Installation

1. **Open in Arduino IDE:** Open `SmartDoorLock.ino`.
2. **Connect Arduino:** Via USB.
3. **Install Libraries:** `LiquidCrystal I2C` and `Keypad` via Arduino Library Manager.
4. **Select Board/Port:** `Tools > Board` and `Tools > Port`.
5. **Upload Code:** Click `Upload` in Arduino IDE.

## Usage

- Enter `1121` to unlock.
- Press `A` to lock after unlocking.
- Press `C` to reset PIN input.

## Future Ideas

- Customizable PIN
- Alarm after incorrect attempts
- Remote control via Bluetooth/Wi-Fi

## License

MIT License. Contributions welcome via Pull Requests.

## Clone the Repository

```bash
git clone https://github.com/AnthonyY-dev/SmartDoorLock.git
```

## Watch youtube video
- Here is the (youtube video)[https://youtu.be/9Cadp6dBYJY] I made on it: https://youtu.be/9Cadp6dBYJY
