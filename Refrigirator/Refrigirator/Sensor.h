#pragma once

#include<iostream>
#include "Light.h"

using namespace std;

class Sensor {

public : 
	virtual void trigerred() = 0;
	virtual void released() = 0;
};

class Door_Sensor: public Sensor {
private:
	Light* door_light;
public:

	Door_Sensor(Door_Light* door_light);
	void trigerred();

	void released();
};
