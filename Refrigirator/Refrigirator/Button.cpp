#include <iostream>
#include "Button.h"
#include"Cooler.h"
using namespace std;


Defrost_Button::Defrost_Button(Freezer_Cooler* freezer_cooler) : freezer_cooler (freezer_cooler) {
	cout << "Freezer Cooler assigned to button\n";
	is_button_pressed = false;
}

void Defrost_Button::on() {
	cout << "Defrost button turned on, Calling defrost() on Freezer_Cooler\n";
	is_button_pressed = true;
	freezer_cooler->defrost();
}

void Defrost_Button::off() {
	cout << "defrost button turned off, Calling freeze() on Freezer_Cooler\n";
	is_button_pressed = false;
	freezer_cooler->freeze();
}

bool Defrost_Button::get_button_status() {
	return this->is_button_pressed;
}




Defrost_Button_Adapter::Defrost_Button_Adapter(On_Off_Button* defrost_button) :defrost_button(defrost_button){
	cout << "Defrost button assigned to adpater/wrapper\n";
}

void Defrost_Button_Adapter::freeze() {
	this->defrost_button->off();
}

void Defrost_Button_Adapter::defrost() {
	this->defrost_button->on();
}

bool Defrost_Button_Adapter::is_currently_in_defrost() {
	return this->defrost_button->get_button_status();
	
}


Fridge_Temp_Button::Fridge_Temp_Button(Fridge_Cooler* fridge_cooler) : fridge_cooler(fridge_cooler) {
	cout << "Fridge Cooler assigned to Fridge temp button\n";
}
void Fridge_Temp_Button::trigerred_button(int temp) {
	cout << "Triggered temp button is calling the cooler to adjust the fridge temperature\n";
	fridge_cooler->cool_fridge(temp);
}

