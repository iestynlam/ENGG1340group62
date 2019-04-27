// takes in a pointer to a commodity struct and prints the commodity to screen in the desired format
#include <iostream>
#include "all_functions.h"
using namespace std;

void print_item(commodity* item) {
  cout << "NAME: " << item->name << "\tMANUFACTURER: " << item->manuf << "\tQUANTITY: " << item->qty << endl;
}
