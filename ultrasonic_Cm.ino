/*
 * ultrasonic_Cm.ino - Sample code for Ultrasonic Ranging Module HC-SR04
 * 
 * Author: Dave Borja <dave.borja@cbsua.edu.ph>
 * Created: February 18, 2021
 * License: GNU GPL v2 or later
 */

#include <ultrasonic.h>  // Ultrasonic Transducer HC-SR04 library

// Create Ultrasonic object with trigger pin 9 and echo pin 10
Ultrasonic ultrasonicSensor(9, 10);

void setup() {
    Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
}

void loop() {
    int distanceCm = ultrasonicSensor.distance_cm();  // Measure distance in cm
    
    Serial.print("Distance in cm: ");
    Serial.println(distanceCm);

    delay(500);  // Delay for readability in serial output
}

/*
 * To measure distance in inches, you can use:
 * 
 * int distanceIn = ultrasonicSensor.distance_in();
 * Serial.println(distanceIn);
 */
