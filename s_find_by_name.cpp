// only to be used within the system, has no error handling for user input
// Can be used when: Only ONE item in linked list matches the EXACT name
#include <string>
#include "all_functions.h"
using namespace std;

string lowercase(string str);

commodity* s_find_by_name(commodity* &head, string target) {
  commodity* current = head;
  while(current!=NULL) {
    if (lowercase(current->name)==target) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}
