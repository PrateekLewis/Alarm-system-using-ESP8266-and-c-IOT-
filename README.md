#ESP8266 Ultrasonic Sensor Intruder Alert System

This project is an ESP8266-based intruder alert system that uses an ultrasonic sensor to detect objects within a specified distance. When an object is detected within the threshold distance, the system sends an alert message to a Telegram bot.

Introduction
This project demonstrates how to use an ESP8266 microcontroller with an ultrasonic sensor to create a simple intruder alert system. The system measures the distance to an object and sends a notification via Telegram when an object is detected within a specified range.

Features
Measures distance using an ultrasonic sensor.
Sends an alert message to a Telegram bot when an object is detected within 20 cm.
Easy to set up and use with the ESP8266 microcontroller.
Uses MicroPython for scripting.

Components-

ESP8266 microcontroller (e.g., NodeMCU)

Ultrasonic sensor (HC-SR04)

Jumper wires

Breadboard

Circuit Diagram

Ultrasonic Sensor (HC-SR04)  | ESP8266 (NodeMCU)
---------------------------- | -----------------
VCC                          | 3V3
GND                          | GND
Trig                         | D1 (GPIO 5)
Echo                         | D2 (GPIO 4)
