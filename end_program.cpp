// Deletes any dynamic memory that has been allocated in the program to avoid memory leak
// Writes all updated information into 'inventory.txt', copies old items intp 'old_inventory.txt' for safekeeping

#include <iostream>
#include <fstream>
using namespace std;

const string filename = "inventory.txt";
const string old_filename = "old_inventory.txt";
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
  // try figure out a way to redirect cout from print_list into 'inventory.txt', something involving
  // rdbuf streambuf? not too sure lol i don't understand stack overflow so im just pasting code for now
  // try to replace with code that redirects print_list()'s output into the file
  commodity* current= head;
  while (current!=NULL) {
    fout_1 << current->name << " " << current->manuf << " " << current->qty << endl;
    current = current->next;
  }
  fout_1.close();
  // cleaning up memory - not certain if this is working
  current = head;
  //loops until only the head is left
  while (current->next!=NULL) {
    //loop until the last item in linked list
    while (current->next!=NULL) {
      current = current->next;
    }
    // deletes item
    delete current;
  }
  delete head;
}
