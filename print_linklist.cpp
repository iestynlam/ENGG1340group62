// Used to print everything in the linked list, can be used to write to file at the end of the program
// also just here for testing whilst writing code

#include <iostream>
using namespace std;

void print_list(commodity* &head) {
  commodity* current= head;
  while (current!=NULL) {
    cout << current->name << " " << current->manuf << " " << current->qty << endl;
    current = current->next;
  }
}
