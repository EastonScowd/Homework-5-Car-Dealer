/**
 *   @file: car-dealer.cc
 * @author: Easton Scowden
 *   @date: 10/31/2019
 *  @brief: A program that allows the user to design a car model with a maximum of 6 add ons, also user should be able to remove add ons if they choose. 
 *          They are also able to reset the whole thing to start a blank car. Program displays price and every add on at the end. 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
using namespace std;

///function prototypes

void displayMenu(int &choice) ; // a function that displays the option menu
void optionOne(char model, double &total, string &modelOfCar, int &choice) ; // a function that picks the model based on user input

int main(int argc, char const *argv[]) {
    int choice ; 
    char model ;
    double total = 0; 
    string modelS ; 

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    displayMenu(choice) ; 

    while(choice != 6){
        switch(choice){
            case 1:
                cout << "Enter the model (E, L, X): " ;
                cin >> model ; 
                optionOne(model, total, modelS, choice) ; 
                break ;
            case 2:

            case 3:

            case 4:
            
            case 5:

            case 6:

            default:
                displayMenu(choice) ; 
        }
        displayMenu(choice) ; 
    }
        

    return 0;
}/// main

void displayMenu(int &choice) {
    cout << "1. Select a model(E, L, X)" << endl ; 
    cout << "2. Display available options and prices" << endl ; 
    cout << "3. Add an option" << endl ; 
    cout << "4. Remove an option" << endl ; 
    cout << "5. Cancel order" << endl ; 
    cout << "6. Quit" << endl ; 
    cout << "Enter a choice: " ; 
    cin >> choice ; // assigning this value to the variable choice in main
}

void optionOne(char model, double &total, string &modelOfCar, int &choice){
    model = toupper(model) ; 
    if(model == 'E'){
        modelOfCar = "Model: E, " ; 
        total = total + 10000 ;  
    } else if(model == 'L'){
        modelOfCar = "Model: L, " ; 
        total = total + 12000 ; 
    } else if(model == 'X'){
        modelOfCar = "Model: X, " ; 
        total = total + 18000 ; 
    } else{
       ;
    }
}