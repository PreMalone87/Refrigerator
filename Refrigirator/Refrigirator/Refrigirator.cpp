#pragma once
// Refrigirator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Button.h"
#include "Cooler.h"
#include "Light.h"
#include "Sensor.h"
#include<thread>
#include<chrono>
#include<vector>

class Refridgirator {

private :

    Cooler* cooler;
    Freezer_Cooler* freezer_coler;
    Fridge_Cooler* fridge_cooler;

    Defrost_Button* defrost_button;
    Defrost_Button_Adapter* defrost_button_adapter;

    Range_Button* fridge_temp_button;


    Door_Light* door_light;
    Sensor* door_sensor;

    char open_door_display_msg() {
        cout << "Do you wanna open door (y/n)\n";
        char option;
        cin >> option;
        return option;
    }

    int options_display_msg() {
        cout << "\nOptions to choose from\n 1.close door\n 2.press_defrost\n 3.adjust temperature\n";
        int option;
        cin >>option;
        return option;
    }

    int temp_selection_display_msg() {
        cout << "\nChoose from the available temperatures : \n2 degrees (2),\n4 degrees(4),\n6 degrees(6),\n8 degrees(8),\n10 degrees(10)\n";
        int temp=-1;
        cin >> temp;

        if (temp != 2 && temp != 4 && temp != 6 && temp != 8 && temp != 10) {
            cout << "Temp provided is invalid\n";
        }

        return temp;
    }

    void close_door() {
        cout << "Closing door and exiting!\n";
        door_sensor->released();
        exit(0);
    }

    void press_defrost() {

        if (defrost_button->get_button_status() == true) {
            "Defrost Button is already pressed.. Please be patient and wait for some more time..\n";
            return;
        }

        cout<<"Pressing Defrost Button..\n";
        defrost_button_adapter->defrost();
        this_thread::sleep_for(chrono::seconds(20));
        //simulating the mechanical tripping of button back to freeze
        defrost_button_adapter->freeze();
    }

    void adjust_temp() {
        cout << "Adjusting temperature..\n";
        int selected_temp = temp_selection_display_msg();
        if (selected_temp == -1) {
            return;
        }
        fridge_temp_button->trigerred_button(selected_temp);
    }

public:

    Refridgirator() {
        cout << "Creating refridgirator objects...\n";

        cooler = new Cooler;
        freezer_coler = new Freezer_Cooler(cooler);
        fridge_cooler = new Fridge_Cooler(cooler);

        defrost_button = new Defrost_Button(freezer_coler);
        defrost_button_adapter = new Defrost_Button_Adapter(defrost_button);

        fridge_temp_button = new Fridge_Temp_Button(fridge_cooler);

        door_light = new Door_Light;
        door_sensor = new Door_Sensor(door_light);


        cout << "Created Refridgrator Objects ..\n";
    }

    void start_fridge(){

        char open_door_option = open_door_display_msg();

        if (open_door_option == 'n'){
            exit(0);
        }
        else if (open_door_option == 'y') {

            vector<thread*>threads;
            while (true) {

                int option = options_display_msg();

                if (option == 1) {
                    close_door();
                }
                else if (option == 2) {
                    //To DO check if already in defrost
                    //vector<thread>threads;
                    cout << "Deforst Pressed!!\n";
                    thread* thread_defrost = new thread(&Refridgirator::press_defrost,this);
                    //threads.push_back(thread_defrost);
                    //press_defrost();
                }
                else if (option == 3) {
                    adjust_temp();
                }
                else {
                    cout << "Please enter a valid option !\n";
                }
            }
            

            
        }
            
    }
};

int main()
{
    

    cout << "Starting refridgirator\n";
    Refridgirator* fridge = new Refridgirator;
    fridge->start_fridge();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
