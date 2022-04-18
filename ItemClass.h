#include "ReadUtils.h"
#include <fstream>
#include <iomanip>
#include <ostream>
using namespace std;

class Cereal{
  public:
    Cereal();
    void readCereal(ifstream &inFile);
    void print(ostream &outfile);
    void readFromUser();
    double getCalCount();
  private:
    enum {MAX_CHAR_ARRAY_SIZE = 100};
    char cerealName[MAX_CHAR_ARRAY_SIZE];
    double cals;
    double gramsProtein;
    double gramsFat;
    double gramsSodium;
    double gramsFiber;
    double gramsCarbs;
    double gramsSugar;
    double servingSize;
};