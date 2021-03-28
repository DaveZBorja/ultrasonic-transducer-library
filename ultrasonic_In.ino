/*
  ultrasonic_In.ino - Sample Code use by Ultrasonic Ranging Module HC - Sr04
  Created by Dave Z. Borja, February-18-2021 

*/

#include <ultrasonic.h> //Ultrasonic Tranducer library

Ultrasonic Ultrasonic(9, 10); // create object first @param trigger second @param echo

int distanceCm; // variable for distance in Centimeter
int distanceIn; // variable for distance in Inches

void setup(){
	Serial.begin(9600); // for Serial communication and boudrate (9600) 
}
void loop(){

	//distanceCm = Ultrasonic.distance_cm(); // function in measuring distances in cm
	//Serial.println(distanceCm); 

	distanceIn = Ultrasonic.distance_in(); // function in measuring distances in in
	Serial.print("Distance in Inches: ");
	Serial.println(distanceIn);
	
}
