#include<iostream>
#include<math.h>
#include "Cooler.h"
using namespace std;


void Cooler::cool(int cooling_value) {
	cout << "Cooler invoked with value " << cooling_value<<endl;
}



Freezer_Cooler::Freezer_Cooler(Cooler *cooler) : cooler(cooler) {
	cout << "Cooler assigned to Freezer Cooler\n" ;
}

int Freezer_Cooler::convert_temp_to_cooler_val(int temp) {
	return sqrt(5000/pow(temp+56, 2) * 4);
}

void Freezer_Cooler::freeze() {
	int cooler_val = convert_temp_to_cooler_val(freeze_temp);
	cout << "Freezer Cooler wrapper is gonna freeze\n";
	cooler->cool(cooler_val);
}

void Freezer_Cooler::defrost() {
	int cooler_val = convert_temp_to_cooler_val(defrost_temp);
	cout << "Freezer Cooler wrapper is gonna defrost\n";
	cooler->cool(cooler_val);
}

	


Fridge_Cooler::Fridge_Cooler(Cooler* cooler) : cooler(cooler) {
	cout << "Cooler assigned to Fridge Cooler\n";
}

int Fridge_Cooler::convert_temp_to_cooler_val(int temp) {
	return sqrt(1 / pow(temp + 56, 2) * 4);
}

void Fridge_Cooler::cool_fridge(int temp) {
	int cooler_val = convert_temp_to_cooler_val(temp);
	cout << "Fridge cooler is gonna call cooler to make cooling to " << cooler_val<<endl;
	cooler->cool(cooler_val);
}
