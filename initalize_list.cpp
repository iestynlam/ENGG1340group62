// CURRENTLY BUGGED, LOTS OF EXTRA FUNCTIONS PASTED HERE FOR TESTING PURPOSES

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string filename = "inventory.txt";

void initialize_list(commodity* &head, string filename) {
  int count=0;
  commodity item;
  string line;
  ifstream fin0 (filename);
  // count how many line are in the file so it knows how many times to loop,
  // there's probably a better way to do this but it works at least
  while (getline(fin0,line)) {
    count++;
  }
  fin0.close();

  ifstream fin1;
  fin1.open(filename);
  for (int i = 0; i<count; i++) {
    fin1 >> item.name >> item.manuf >> item.qty;
    append_item(head, item.name, item.manuf, item.qty);
  }
  fin1.close();
} // void initialize_list //
