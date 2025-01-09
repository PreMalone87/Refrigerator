#pragma once
#include <iostream>
#include"Cooler.h"
using namespace std;



class On_Off_Button {
public:
	virtual void on() = 0;
	virtual void off() = 0;
	virtual bool get_button_status() = 0;
};



class Defrost_Button : public On_Off_Button {

private:
	Freezer_Cooler* freezer_cooler;
	bool is_button_pressed;
public:
	Defrost_Button(Freezer_Cooler* freezer_cooler);

	//mechanically the button automatically turns off after some particular time
	void on();
	void off();
	bool get_button_status();
};


//Object adpater/wrapper for Defrost button
class Defrost_Button_Adapter {
private:
	On_Off_Button* defrost_button;
public:
	Defrost_Button_Adapter(On_Off_Button* defrost_button) ;

	void freeze();

	void defrost();

	bool is_currently_in_defrost();
};


class Range_Button {
public:
	int button_val;
	virtual void trigerred_button(int button_val) = 0;

};

class Fridge_Temp_Button : public Range_Button {
private:
	Fridge_Cooler* fridge_cooler;
public:

	Fridge_Temp_Button(Fridge_Cooler* fridge_cooler) ;
	void trigerred_button(int temp);
};
