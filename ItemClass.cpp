#include "ItemClass.h"
#include <iostream>
using namespace std;

//default constructor
Cereal::Cereal(){
  for (int index = 0; index < MAX_CHAR_ARRAY_SIZE; index++) {
        cerealName[index] = '\0';
    }
  cals = 0;
  gramsProtein = 0;
  gramsFat = 0;
  gramsSodium = 0;
  gramsFiber = 0;
  gramsCarbs = 0;
  gramsSugar = 0;
  servingSize = 0;
}

//reads information from a file and fills in the fields of a cereal
void Cereal::readCereal(ifstream &inFile){ 
    inFile.get(cerealName, Cereal::MAX_CHAR_ARRAY_SIZE, ';');
    inFile.ignore(100,';');
    inFile >> cals;
    inFile.ignore(100,';');
    inFile >> gramsProtein;
    inFile.ignore(100,';');
    inFile >> gramsFat;
    inFile.ignore(100,';');
    inFile >> gramsSodium;
    inFile.ignore(100,';');
    inFile >> gramsFiber;
    inFile.ignore(100,';');
    inFile >> gramsCarbs;
    inFile.ignore(100,';');
    inFile >> gramsSugar;
    inFile.ignore(100, ';');
    inFile >> servingSize;
    inFile.ignore(100,'\n');
}

// prints the information of a cereal
void Cereal:: print(ostream &outFile){
  outFile << cerealName << "; " << cals << "; " << gramsProtein << "; " << gramsFat << "; " << gramsSodium << "; " << gramsFiber << "; " << gramsCarbs << "; " << gramsSugar << "; " << servingSize << endl;
}

//takes user input to fill in the fields of a cereal
void Cereal:: readFromUser(){
  cout << "enter the cereal name: " << endl;
    cin.ignore(100, '\n');
    cin.getline(cerealName, MAX_CHAR_ARRAY_SIZE); 
   cals = readDouble("enter the number of calories per serving: ");
    gramsProtein = readInt("enter the grams of protein per serving: ");
    gramsFat = readDouble("enter the grams of fat per serving: ");
    gramsSodium = readDouble("enter the grams of sodium per serving: ");
    gramsFiber = readDouble("enter the grams of fiber per serving: ");
   gramsCarbs = readDouble("enter the grams of carbs per serving: ");
    gramsSugar = readDouble("enter the grams of sugar per serving: ");
  servingSize = readDouble("enter the serving size: ");
}

//accessor for the number of calories in a cereal
double Cereal::getCalCount(){
  return cals;
}