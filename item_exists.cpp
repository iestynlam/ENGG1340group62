/* Goes through linked list via head pointer and determines whether an item
exists in the system with the same name already, needs to be modified so that it
returns different values for same name but different manufacturer, only one match,
and no match */

#include <iostream>
using namespace std;

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
