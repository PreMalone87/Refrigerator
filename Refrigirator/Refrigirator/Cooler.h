#pragma once
#include<iostream>
#include<math.h>
using namespace std;

class Cooler {
public:
	void cool(int cooling_value);
};

class Freezer_Cooler {
private:
	Cooler* cooler;
	int freeze_temp = 0;
	int defrost_temp = 10;

public:
	Freezer_Cooler(Cooler* cooler);

	int convert_temp_to_cooler_val(int temp);

	void freeze();

	void defrost();


};

class Fridge_Cooler {
public:
	Cooler* cooler;

public:
	Fridge_Cooler(Cooler* cooler);

	int convert_temp_to_cooler_val(int temp);

	void cool_fridge(int temp);

};