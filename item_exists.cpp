/* Goes through linked list via head pointer and determines whether an item
exists in the system with the same name already */

#include <iostream>
using namespace std;

bool item_exists(commodity* &head, string item_name) {
  commodity* current = head;
  while (current!=NULL) {
    if (lowercase(current->name) == lowercase(item_name)) {
      return true;
    }
    current = current->next;
  }
  return false;
}
