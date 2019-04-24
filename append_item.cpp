// Appends a new commodity to the linked list of items, THIS WORKS
#include <iostream>
#include <string>
using namespace std;

void append_item(commodity* &head, string name, string manuf, int qty) {
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
    while (cursor->next!=NULL) {
      cursor = cursor->next;
    }
    cursor->next = a;
  }
}
