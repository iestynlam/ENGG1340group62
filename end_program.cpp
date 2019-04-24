// Deletes any dynamic memory that has been allocated in the program to avoid memory leak
// Writes all updated information into 'inventory.txt', copies old items intp 'old_inventory.txt' for safekeeping

#include <iostream>
#include <fstream>
using namespace std;

const string filename = "inventory.txt";
/*
- clears 'old_inventory.txt'
- copies 'inventory.txt' into 'old_inventory.txt'
- clears 'inventory.txt'
- writes linked list into 'inventory.txt'
*/

void end_program(commodity* &head) {
  ifstream fin (filename);
  ofstream
}
