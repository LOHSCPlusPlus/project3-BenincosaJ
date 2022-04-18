#include "ItemDB.h"
#include <iostream>
using namespace std;

//default constructor for a dataBase
CerealDataBase::CerealDataBase(){
  numCereals = 0;
  readCerealData();
}

//reads the information from the file
int CerealDataBase::readCerealData() {
    ifstream cerealFile("cereal.txt");
    int numCereal = 0;
    while(cerealFile.peek() != EOF && numCereal < MAX_CEREAL) {
        cerealArray[numCereal].readCereal(cerealFile);
        numCereal++;
    }
    return numCereal;  
}

//prints out all the cereals and their information
void CerealDataBase::printCereals(ostream &outFile, bool printIndex){
  for (int index = 0; index < MAX_CEREAL; index++){
    if(printIndex) {
       outFile << "Index " << index << ": ";
    }
   
      cerealArray[index].print(outFile);
        }
}

//allows user to add cereal to the database
void CerealDataBase::addCereal(){
  if(numCereals < MAX_CEREAL){
    cerealArray[numCereals].readFromUser();
    numCereals++;
  }
  
    
else{
    cout << "Database is full" << endl;
    
  }
}

//allows user to remove a dereal from the database
void CerealDataBase::removeCereal(){
  int indexToRemove = readInt("enter an index to remove: ");
  for (int i = indexToRemove; i < MAX_CEREAL - 1; i++){
    cerealArray[i] = cerealArray[i+1];
  }
}

//saves the database
void CerealDataBase::printArrayToFile(const char fileName[]) {
    ofstream outFile(fileName);
    printCereals(outFile, false);
    
}

//prints the cereals with a calorie count greater than a number specified by a user
//uses an accessor to get the cal count of each cereal
void CerealDataBase::searchByCal(){
  
  double userCalCount = readDouble("enter a calorie count");
  
  for (int index = 0; index < MAX_CEREAL; index++){
    if(cerealArray[index].getCalCount() > userCalCount){
           cout << "Index " << index << ": ";
      cerealArray[index].print(cout);
    }

     
  }
}