#pragma once
#include<iostream>

using namespace std;


class Light {
public:
	virtual void on() = 0;
	virtual void off() = 0;

};

class Door_Light : public Light {
public:
	void on();
	void off();
};


