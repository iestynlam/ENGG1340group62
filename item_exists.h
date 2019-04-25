/* Goes through linked list via head pointer and determines whether an item
exists in the system with the same name already, needs to be modified so that it
returns different values for same name but different manufacturer, only one match,
and no match */
#include <iostream>
#include "lowercase.h"
using namespace std;

struct commodity {
  string name; // name of commodity
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;

int item_exists(commodity* &head, string item_name) {
  commodity* current = head;
  while (current!=NULL) {
    if (lowercase(current->name) == lowercase(item_name)) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}
