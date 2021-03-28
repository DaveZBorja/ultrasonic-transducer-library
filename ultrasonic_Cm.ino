/*
 * ultrasonic_Cm.ino - Sample Code use by Ultrasonic Ranging Module HC - Sr04
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

#include <ultrasonic.h> //Ultrasonic Tranducer HC - SR04 library

Ultrasonic Ultrasonic(9, 10); // create Ultrasonic object first @param trigger second @param echo

int distanceCm; // variable for distance in Centimeter
int distanceIn; // variable for distance in Inches

void setup(){
	Serial.begin(9600); // for Serial communication with a boudrate (9600) 
}
void loop(){
	distanceCm = Ultrasonic.distance_cm(); // function in measuring distances in cm
	Serial.print("Distance in Cm: ");
	Serial.println(distanceCm);
	
}

/*
* PS: no more hard-coded 
*
* Exmple:
*       
*		// To measure the distance in Inches
*		
*		distanceIn = Ultrasonic.distance_in(); // function in measuring distances in in
*		Serial.println(distanceIn);
*/
	
