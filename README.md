# Bitwise Control Pipeline

## Project Description
An ESP32-based system that utilizes a 74HC595 serial-to-parallel integrated circuit (shift register) to control 8 respective LEDs connected to its output pins. The project utilizes bit shifting and SPI communication to accurately drive each LED, visually representing the binary byte sequence being transmitted.

## Schematic
<img width="665" height="500" alt="Screenshot 2026-07-02 210122" src="https://github.com/user-attachments/assets/76cc2bb8-3275-46e3-89e1-27fe71d43f6b" />
*Schematic is shown with an ESP32, 74HC595 integrated circuit, and LEDs. All hardware is compatible with original system and GPIO pins stay consistent.*

## Hardware and Software Requirements

### Hardware Requirements

* ESP32 Development Board
* 74HC595 Serial-to-Parallel Integrated Circuit
* 8 LEDs
* Breadboard, Jumper Wires, Micro-USB/USB-C

### Software Requirements

* Recommended: Visual Studio Code IDE with ESP-IDF Extension
* Espressif IoT Development Framework (ESP-IDF)
* CMake and Ninja Build Systems
* Windows 10/11, Linux, MacOS

See docs page on how to build the environment for this system.
