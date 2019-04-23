// CURRENTLY BUGGED, LOTS OF EXTRA FUNCTIONS PASTED HERE FOR TESTING PURPOSES

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string filename = "inventory.txt";
// Struct used to hold details of all commodities. [FOR REFERENCE]
// Not sure if this is actually necessary if its all compiled together
struct commodity {
  string name; // name of commodity
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;

void appendCommodity(commodity* &head, string name, string manuf, int qty) {
  commodity* a = new commodity;
  a->name = name;
  a->manuf = manuf;
  a->qty = qty;
  a->next = NULL;

  if (head==NULL) {
    head = a;
  }
  else {
    commodity* cursor = head;
    while (cursor!=NULL) {
      if (cursor->next==NULL) {
        cursor->next = a;
      }
      cursor = cursor->next;
    }
  }
}

void printCar(commodity* &head) {
  commodity* current = head;
  while (current != NULL) {
    if (current->next != NULL) {
      cout << current->name << ",";
    }
    else {
      cout << current->name;
    }
    current = current->next;
  }
}

// Loops through each line of the file and takes the information and inputs it into a linked list.
// this program currently assumes that all strings have no spaces - will probably need to be updated to accept spaces,
// or identifiers can have specific requiremetns (no spaces, however search functions will account for spaces and replace with underscores)
void initialize_list(commodity* &head, string filename) {
  int count = 0, qty;
  ifstream fin (filename);
  string line, name, manuf;
  while (getline(fin,line)) {
    count++;
  }
  for (int i = 0; i<count; i++) {
    fin >> name >> manuf >> qty;
  }
  appendCommodity(head, name, manuf, qty);
} // void initialize_list //

int main() {
  commodity* head = NULL;
  initialize_list(head, filename);
  printCar(head);
}
