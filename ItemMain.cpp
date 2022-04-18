#include <iostream>
#include "ItemDB.h"
using namespace std;

const int MAX_MENU_LEN = 70;
void printMenu(char options[][MAX_MENU_LEN], int numEntries) {
    for (int index = 0; index < numEntries; index++) {
        cout << (index + 1) << ") " << options[index] << endl;
    }
}
// Interact with the database functions using a menu to choose what to do
int main() {
  CerealDataBase dataBase;
  int option = 0; 
  char menuOptions[][MAX_MENU_LEN]={
  "Print Cereal List",

  "Save list to file",

  "Remove cereal",

  "Add cereal",

  "Search by calorie count",

  "Quit"};
    dataBase.readCerealData();
  
  do {
        printMenu(menuOptions,6);
        option = readInt("Please select an option: ");
        switch(option) {
            case 1:
                dataBase.printCereals(cout, true);
                break;
            case 2:
                dataBase.printArrayToFile("test.txt");
                break;
            case 3:
                dataBase.removeCereal();
                break;
            case 4:
                dataBase.addCereal();
                break;
            case 5:
                dataBase.searchByCal();
                break;
            case 6:
                break;
            default:
                cout << "Invalid option, try again" << endl;
                break;
        }
    }while(option != 6);
    
    return 0;
}
