// INTRODUCTORY MESSAGE & MESSAGES INDICATING USER CAN PROCEED

#include <iostream>
#include "all_functions.h"
using namespace std;

void intro(int x) {
  if (x == 0) { // first intro message
    cout << "// Welcome to the commodity manager! //" << endl << "\nType \"options\" to view available "
    "actions and \"help\" for further details regarding available options. Type \"exit\" "
    "to shut down the program." << endl;
  }
  cout << endl << "PLEASE INPUT YOUR SELECTED OPTION TO PROCEED: " << endl;
}
