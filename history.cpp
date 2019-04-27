#include <iostream>
#include <fstream>

void history(string inventory_history){
  ifstream history;
  history.open(inventory_history.c_str());
  string line;
  while (getline(history, line)){
    cout << line << endl;
  }
  history.close();
}
