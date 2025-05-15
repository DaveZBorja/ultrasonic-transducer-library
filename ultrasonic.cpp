/*
 * ultrasonic.h - Interface for Ultrasonic Ranging Module HC-SR04
 * 
 * Author: Dave Borja <dave.borja@cbsua.edu.ph>
 * Created: February 18, 2021
 * License: GNU GPL v2 or later
 */

#include "ultrasonic.h"

Ultrasonic::Ultrasonic(int trigPin, int echoPin) {
    _trig = trigPin;
    _echo = echoPin;

    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);

    // Cache register and bit mask for fast digitalWrite replacement
    _trig_port = digitalPinToPort(_trig);
    _trig_bit_mask = digitalPinToBitMask(_trig);
    _trig_out = portOutputRegister(_trig_port);
}

int Ultrasonic::distance_cm() {
    // LOW pulse
    *_trig_out &= ~_trig_bit_mask;
    delayMicroseconds(2);

    // HIGH pulse
    *_trig_out |= _trig_bit_mask;
    delayMicroseconds(10);

    // LOW pulse again
    *_trig_out &= ~_trig_bit_mask;

    long duration = pulseIn(_echo, HIGH);
    return duration * 0.034 / 2;
}

int Ultrasonic::distance_in() {
    *_trig_out &= ~_trig_bit_mask;
    delayMicroseconds(2);

    *_trig_out |= _trig_bit_mask;
    delayMicroseconds(10);

    *_trig_out &= ~_trig_bit_mask;

    long duration = pulseIn(_echo, HIGH);
    return duration * 0.0113 / 2;
}
