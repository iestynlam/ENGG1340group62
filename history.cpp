#include <iostream>
#include <fstream>
#include "all_functions.h"
using namespace std;

// prints all of the lines in the inventory_history file
const string inventory_history = "inventory_history.txt";

void history(string inventory_history) {
  ifstream history;
  history.open(inventory_history.c_str());
  string line;
  while (getline(history, line)){
    cout << line << endl;
  }
  history.close();
}
