#include "ItemClass.h"
class CerealDataBase{
  public:
    CerealDataBase();
    int readCerealData();
    void printCereals(ostream &outFile,        bool printIndex);
    //allows user to add a cereal to the database
    void addCereal();
    //allows user to remove a cereal from the database
    void removeCereal();
    //this is the save function
    void printArrayToFile(const char     
    fileName[]);
    //prints the cereals that have a calorie count over a number specified by user
    void searchByCal();
  private:
    enum{MAX_CEREAL = 50};
    Cereal cerealArray[MAX_CEREAL];
    int numCereals;
};