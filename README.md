# ESP32 Fingerprint Authentication System

## Overview

This project implements a biometric authentication system using an ESP32 microcontroller and an R307S fingerprint sensor. The system enrolls and stores fingerprint templates in the sensor's internal memory and verifies users based on fingerprint matching.

A green LED indicates successful authentication, while a red LED indicates an unauthorized fingerprint.

## Features

* Fingerprint enrollment and storage
* Fingerprint verification and identification
* Green LED indication for authorized users
* Red LED indication for unauthorized users
* UART communication between ESP32 and R307S
* Real-time biometric authentication

## Hardware Components

* ESP32 DevKit
* R307S Fingerprint Sensor
* Green LED
* Red LED
* 220Ω Resistors
* Breadboard
* Jumper Wires

## Circuit Connections

### Fingerprint Sensor

| R307S | ESP32        |
| ----- | ------------ |
| VCC   | VIN (5V)     |
| GND   | GND          |
| TX    | GPIO16 (RX2) |
| RX    | GPIO17 (TX2) |

### LEDs

| Component | ESP32  |
| --------- | ------ |
| Green LED | GPIO13 |
| Red LED   | GPIO12 |

## Working Principle

1. Enroll fingerprints into the R307S sensor memory.
2. Place a finger on the sensor.
3. The sensor captures and processes the fingerprint image.
4. The fingerprint is compared with stored templates.
5. If a match is found, the green LED turns ON.
6. If no match is found, the red LED turns ON.


## Applications

* Attendance Management Systems
* Smart Door Locks
* Access Control Systems
* Embedded Security Projects

## Technologies Used

* Embedded C/C++
* ESP32
* UART Communication
* Arduino IDE
* Adafruit Fingerprint Sensor Library

## Future Improvements

* OLED Display Integration
* RFID Authentication
* Wi-Fi Attendance Logging
* Cloud Database Storage
* Relay-Based Door Lock Control
