/*
 * ultrasonic.h - Interface for Ultrasonic Ranging Module HC-SR04
 * 
 * Author: Dave Borja <dave.borja@cbsua.edu.ph>
 * Created: February 18, 2021
 * License: GNU GPL v2 or later
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class Ultrasonic {
public:
    Ultrasonic(int trig, int echo);
    int distance_cm();  // Measure distance in centimeters
    int distance_in();  // Measure distance in inches

private:
    int _trig;
    int _echo;

    // For direct port manipulation (speed optimization)
    volatile uint8_t* _trig_out;
    uint8_t _trig_bit_mask;
    uint8_t _trig_port;
};

#endif  // ULTRASONIC_H
