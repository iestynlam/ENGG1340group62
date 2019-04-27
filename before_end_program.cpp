#include <fstream>
#include <string>
#include "all_functions.h"
using namespace std;
const string filename = "inventory.txt";
const string old_filename = "old_inventory.txt";
const string inventory_history = "inventory_history.txt";
const string buffer = "buffer.txt";

void write_history(string filename, string inventory_history);
bool same(string buffer, string old_filename);

void before_end_program(commodity* head){
  //creating a txt file, buffer,  to save the linked list
  ofstream fout_2 (buffer);
  commodity* current1= head;
  while (current1!=NULL) {
    fout_2 << current1->name << " " << current1->manuf << " " << current1->qty << endl;
    current1 = current1->next;
  }
  fout_2.close();
  // if linked list and old_inventory.txt is different
  if (!same(buffer, old_filename)){
    write_history(buffer, inventory_history);
  }
}
