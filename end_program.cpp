// Deletes any dynamic memory that has been allocated in the program to avoid memory leak
// Writes all updated information into 'inventory.txt', copies old items intp 'old_inventory.txt' for safekeeping

#include <iostream>
#include <fstream>
using namespace std;

const string filename = "inventory.txt";
const string old_filename = "old_inventory.txt";
const string history = "inventory_history.txt";
const string buffer = "buffer.txt";
/*
- clears 'old_inventory.txt'
- copies 'inventory.txt' into 'old_inventory.txt'
- clears 'inventory.txt'
- writes linked list into 'inventory.txt'
- clear linked list to clean up memory
*/

void end_program(commodity* &head) {
  // copy pasting inventory into old_inventory
  ifstream fin (filename);
  ofstream fout_0 (old_filename);
  string line;
  while (getline(fin,line)) {
    fout_0 << line << endl;
  }
  fin.close();
  fout_0.close();
  // printing linked list into 'inventory.tct'
  ofstream fout_1 (filename);
  commodity* current= head;
  while (current!=NULL) {
    fout_1 << current->name << " " << current->manuf << " " << current->qty << endl;
    current = current->next;
  }
  fout_1.close();
  // cleaning up memory
  while (current->next!=NULL) {
    head = head->next;
    delete current;
    current = head;
  }
}
