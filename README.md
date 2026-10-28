# 🚨 LeakLock: LPG Gas Leak Detector with Escalating Alarm

An Arduino Uno project that raises its alert as the gas level rises, instead of just switching a buzzer ON or OFF.

## Alert Levels
- 🟢 Safe: green LED, silent
- 🟡 Medium: yellow LED, slow beep
- 🟠 High: orange LED, fast beep
- 🔴 Critical: red LED, siren

## How It Works
- The sensor value (0-1023) is read on pin A0
- It is compared with three thresholds: 256, 512 and 768
- Only the matching LED lights up, and the buzzer pattern changes
- The Serial Monitor logs every reading and its status

## Components
- Arduino Uno
- Potentiometer (simulates the MQ-6 gas sensor)
- Buzzer
- 4 LEDs (green, yellow, orange, red)
- 4 x 220 ohm resistors

## Tools
Tinkercad, Embedded C (Arduino)

## Demo
Turn the potentiometer knob from minimum to maximum to see all four states.

## Files
- LeakLock.ino: Arduino code
- circuit.png: circuit screenshot

## Author
Sunmathi Manivelan
Internship: Embedded IoT System Design, Sans Innovations, Salem
