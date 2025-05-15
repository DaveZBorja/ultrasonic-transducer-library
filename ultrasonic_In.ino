/*
 * ultrasonic_In.ino - Sample code for Ultrasonic Ranging Module HC-SR04
 * 
 * Author: Dave Borja <dave.borja@cbsua.edu.ph>
 * Created: February 18, 2021
 * License: GNU GPL v2 or later
 */

#include <ultrasonic.h>  // Ultrasonic Transducer HC-SR04 library

// Create Ultrasonic object with trigger pin 9 and echo pin 10
Ultrasonic ultrasonicSensor(9, 10);

void setup() {
    Serial.begin(9600);  // Initialize serial communication at 9600 baud
}

void loop() {
    int distanceIn = ultrasonicSensor.distance_in();  // Measure distance in inches

    Serial.print("Distance in Inches: ");
    Serial.println(distanceIn);

    delay(500);  // Small delay for easier reading in serial monitor
}
