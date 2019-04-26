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
// return Ture if the two files are the same
bool same(string buffer, string old_filename);
// append the inventory into inventory_history
void write_history(string inventory ,string inventory_history);

void end_program(commodity* &head) {
  //creating a txt file to save the linked list
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
  // cleaning up memory - not certain if this is working [needs checking]
  current = head;
  //loops until only the head is left
  if (head->next==NULL) {
    delete head;
  }

  while (current->next!=NULL) {
    head = head->next;
    delete current;
    current = head;
  }
}

void write_history(string filename ,string inventory_history){
  ofstream write;
  write.open(inventory_history.c_str(), ios::app);
  ifstream input;
  input.open(filename.c_str());
  string line;

  time_t t = time(0);   // get time now
  tm* now = localtime(&t); // pointer to localtime
  write << endl << now->tm_mday << '-' << (now->tm_mon + 1) << '-' <<  (now->tm_year + 1900) << endl;
  while (getline(input, line)){
    write << line << endl;
  }
  write.close();
  input.close();
}

bool same(string buffer, string old_filename){
  ifstream update;
  update.open(buffer.c_str());
  ifstream old;
  old.open(old_filename.c_str());
  string l1,l2;
  while (getline(update,l1) || (getline(old,l2))){
    getline(old,l2);
    if (l1 != l2){
      update.close();
      old.close();
      return false;
    }
  }
  update.close();
  old.close();
  return true;
}
