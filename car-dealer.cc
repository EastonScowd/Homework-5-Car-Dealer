/**
 *   @file: car-dealer.cc
 * @author: Easton Scowden
 *   @date: 10/31/2019
 *  @brief: A program that allows the user to design a car model with a maximum of 6 add ons, also user should be able to remove add ons if they choose. 
 *          They are also able to reset the whole thing to start a blank car. Program displays price and every add on at the end. 
 */

////////////////////////////////////////////////////////////////
// To DOs:
// make option non case sensitive
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <vector> 
#include <fstream>
#include <string>
#include <algorithm> 
#include <locale>
using namespace std;

///function prototypes

void displayMenu(int &choice) ; // a function that displays the option menu
void optionOne(char model, double &total, string &modelOfCar, int &choice) ; // a function that picks the model based on user input
void addOpt(string &option, vector<string> names, vector<double> prices, vector<string> &selectedChoice, double &total, int &choice) ; 
void printLn(vector<string> selectedChoice, double total, char model) ; 
void displayNames(vector<string> names, vector<double> prices, int vCounts) ; 
void cancelOrder(char &model, vector<string> &selectedChoice, double &total) ; 
void removeOpt(string &option, vector<string> &selectedChoice, double &total, vector<double> prices, vector<string> names) ; 
string toUpper(string one) ; 

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
    string nameOfOption ; 
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
                displayNames(names, prices, vCount) ; 
                break ; 
            case 3:
                if(selectedChoice.size() != 6){
                    if(model == 'P' ){
                        cout << "Please enter a model." << endl ; 
                    } else {    
                        addOpt(option, names, prices, selectedChoice, total, choice) ;
                        printLn(selectedChoice, total, model) ;
                    }
                } else {
                    cout << "You already have six options." << endl ; 
                }
                break ; 
            case 4:
                removeOpt(option, selectedChoice, total, prices, names) ; 
                printLn(selectedChoice, total, model) ;
                break ; 
            case 5:
                cancelOrder(model, selectedChoice, total) ; 
                break ;
            case 6:

            default:
                break ; 
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
    cout << "Enter an option name: " ; 
    cin >> ws ;
    getline(cin, option) ; 
    int found = 0 ;

    for(size_t i = 0; i < names.size(); i++){
        if(toUpper(option) == toUpper(names[i])){
            found = i ; 
            for(size_t i = 0; i < selectedChoice.size(); i++){
                if(toUpper(option) == toUpper(selectedChoice[i])){
                    cout << "You have already selected this option." << endl ; 
                    cout << selectedChoice[i] ; 
                    return ; 
                }
            }
            total += prices[found] ;
            selectedChoice.push_back(names[i]) ;
        } 
    } 
}

void removeOpt(string &option, vector<string> &selectedChoice, double &total, vector<double> prices, vector<string> names){
    cout << "Enter an option name to remove: " ; 
    cin >> ws ;
    getline(cin, option) ; 
    int found = 0;

    for(size_t i = 0; i < selectedChoice.size(); i++){
        if(toUpper(option) == toUpper(selectedChoice[i])){
            found = i ;   
        } else { 
            continue ; 
        }
    }

    for(size_t i = 0; i < names.size(); i++){
        if(toUpper(option) == toUpper(names[i])){
            total -= prices[i] ; 
        } 
    }

    selectedChoice.erase(selectedChoice.begin()+found) ; 

}

void displayNames(vector<string> names, vector<double> prices, int vCount){
    int threePer = 0 ;
    cout << "Model E: $10,000, Model S: $12,0000, Model X: $18,000" << endl ; 
    for(int i = 0; i < vCount; i++){
         cout << setw(25) << left << names[i] << "($" << prices[i] << ") ";
         threePer ++ ; 
         if(threePer == 3){
             cout << endl ; 
             threePer = 0 ; 
         }
    }
       
}

void cancelOrder(char &model, vector<string> &selectedChoice, double &total){
    model = 'P' ; 
    total = 0.0 ; 
    selectedChoice.clear() ; 
    cout << "Order canceled." << endl ; 
}



void printLn(vector<string> selectedChoice, double total, char model){
    if(model == 'P'){
        cout << "Please enter a model." << endl ; 
    } else {
        cout << "Model " << model << " " << total << ", " << "Options: " ;
        if(selectedChoice.size() == 0){
            cout << endl ; 
        } else {
            for(size_t i = 0; i < selectedChoice.size()-1; i++){
            cout << selectedChoice[i] << ", " ; 
            }
            cout << selectedChoice.back() << endl ; 
        }
    }
}

string toUpper(string one){
    for(size_t i = 0; i < one.length(); i++){
        one[i] = toupper(one[i]) ; 
    }
    return one ; 
}