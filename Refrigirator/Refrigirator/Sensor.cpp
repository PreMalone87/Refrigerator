#include<iostream>
#include"Sensor.h"
#include "Light.h"

using namespace std;


Door_Sensor::Door_Sensor(Door_Light* door_light) : door_light(door_light) {
	cout << "Door light assigned to door Sensor\n";
}
void Door_Sensor::trigerred() {
	door_light->on();
}

void Door_Sensor::released() {
	door_light -> off();
}
