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
#include <vector> 
#include <fstream>
#include <string>
#include <algorithm> 
using namespace std;

///function prototypes

void displayMenu(int &choice) ; // a function that displays the option menu
void optionOne(char model, double &total, string &modelOfCar, int &choice) ; // a function that picks the model based on user input
void addOpt(string &option, vector<string> names, vector<double> prices, vector<string> &selectedChoice, double &total, int &choice) ; 
void printLn(vector<string> selectedChoice, double total, char model) ; 

int main(int argc, char const *argv[]) { 
    vector<string> names(30) ; 
    vector<string> selectedChoice(0) ; 
    vector<double> prices(30) ;
    ifstream in ; 
    int choice ; 
    char model = 'P' ;
    double total = 0 ; 
    string modelS ; 
    int count = 0 ;
    int vCount = 0 ;  
    string option ; 
    double ePrice = 10000 ; 
    double lPrice = 12000 ; 
    double xPrice = 18000 ; 

    cout.setf(ios::fixed); 
    cout.setf(ios::showpoint); 
    cout.precision(2); 
    
    in.open("options.txt") ; 

    if(in.fail()) {
        cout << "File error" << endl ; 
        return -1 ; 
    }

    while(in >> prices[vCount]){
        getline(in, names[vCount]) ;
        vCount ++ ;  
    }

    for(int i = 0; i < vCount; i++){
        names[i] = names[i].substr(1, (names[i]).length()-1) ; 
    }

    in.close() ; 

    displayMenu(choice) ; 

    while(choice != 6){
        switch(choice){
            case 1:
                count ++ ; 
                if(count > 1){
                    if(model == 'E'){
                        total -= ePrice ; 
                    } else if(model == 'L'){
                        total -= lPrice ; 
                    } else{
                        total -= xPrice  ;
                    }
                    cout << "Enter the model (E, L, X): " ;
                    cin >> model ; 
                    optionOne(model, total, modelS, choice) ; 
                } else {
                    cout << "Enter the model (E, L, X): " ;
                    cin >> model ; 
                    optionOne(model, total, modelS, choice) ; 
                }
                printLn(selectedChoice, total, model) ; 
                break ;
            case 2:

            case 3:
                addOpt(option, names, prices, selectedChoice, total, choice) ;
                printLn(selectedChoice, total, model) ; 
                break ; 
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
        total += 10000 ;  
    } else if(model == 'L'){
        modelOfCar = "Model: L, " ; 
        total += 12000 ; 
    } else if(model == 'X'){
        modelOfCar = "Model: X, " ; 
        total += 18000 ; 
    } else{
       ;
    }
}

void addOpt(string &option, vector<string> names, vector<double> prices, vector<string> &selectedChoice, double &total, int &choice){
    int count = 0 ;
    cout << "Enter an option name: " ; 
    cin >> ws ;
    getline(cin, option) ; 

    if(find(names.begin(), names.end(), option) != names.end()){
        if(find(selectedChoice.begin(), selectedChoice.end(), option) != selectedChoice.end()){
            cout << "You have already selected this." << endl ; 
        }  else {
            selectedChoice.push_back(option) ; 
        }
    } else {
        cout << "Invalid option." << endl ; 
    }

    while(names[count] != option){
        count ++ ; 
    }
    
    total += prices[count] ; 
}

void printLn(vector<string> selectedChoice, double total, char model){
    if(model == 'P'){
        cout << "Please enter a model." << endl ; 
    } else {
        cout << "Model " << model << " " << total << ", " << "Options: " ;
        if(selectedChoice.size() == 0){
            cout << endl ; 
        } else {
            for(size_t i = 0; i < selectedChoice.size(); i++){
            cout << selectedChoice[i] << ", " ; 
            }
            cout << endl ; 
        }
    }
}