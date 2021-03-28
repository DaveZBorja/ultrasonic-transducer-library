/*
 * ultrasonic.cpp - Code use by Ultrasonic Ranging Module HC - Sr04
 * 
 * Copyright 2019 <dave.borja@cbsua.edu.ph>
 * Created date: February-18-2021
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "ultrasonic.h"

Ultrasonic::Ultrasonic(int trig, int echo){
   
    pinMode(echo, INPUT);
    _echo = echo;
    pinMode(trig, OUTPUT);
    _trig = trig;

}

int Ultrasonic::distance_cm(){
    digitalWrite(_trig, LOW);
    delayMicroseconds(2);

    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    long duration = pulseIn(_echo, HIGH);
    int distance_cm = duration * 0.034 / 2;

    return distance_cm;
}
int Ultrasonic::distance_in(){
    digitalWrite(_trig, LOW);
    delayMicroseconds(2);

    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    long duration = pulseIn(_echo, HIGH);
    int distance_in = duration*0.0113/2;

    return distance_in;

  
}
