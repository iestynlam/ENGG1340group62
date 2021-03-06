/* Reads user input to determine what criteria to display stored data by, allows for
- alphabetical by name
- alphabetical by manufacturer
- quantity high to low
- quantity low to high
Outputs the list in determined order, does not actually reorganize list.
*/
#include <iostream>
#include <string>
#include "all_functions.h"
using namespace std;

void swap_commodity(commodity &a, commodity &b);
void print_item(commodity* item);

void display(commodity* &head) {
  commodity* current = head;
  cout << "Select order to display in:\n1. Alphabetical (Name)\n2. Alphabetical (Manufacturer)"
  "\n3. High to low quantity\n4. Low to high quantity\n";

  int choice,count=0;
  //convert linked list into a dynamically allocated array to be sorted later
  while (current!=NULL) {
    count++;
    current = current->next;
  }
  commodity* set = new commodity[count];
  current = head;
  for (int i=0;i<count;i++) {
    set[i] = *current;
    current = current->next;
  }
  cin >> choice;
  // aplhabetical by name
  if (choice == 1) {
    cout << "All items in alphabetical order (by name):\n";
    for (int i=1; i<count; i++) {
      for (int j=0; j<(count-1); j++) {
        if (set[j].name > set[j+1].name) {
          swap_commodity(set[j],set[j+1]);
        }
      }
    }
  }
  // alphabetical by manuf
  else if (choice == 2) {
    cout << "All items in alphabetical order (by manufacturer):\n";
    for (int i=1; i<count; i++) {
      for (int j=0; j<(count-1); j++) {
        if (set[j].manuf > set[j+1].manuf) {
          swap_commodity(set[j],set[j+1]);
        }
      }
    }
  }
  // high to low
  else if (choice == 3) {
    cout << "All items from high to low quantity:\n";
    for (int i=1; i<count; i++) {
      for (int j=0; j<(count-1); j++) {
        if (set[j].qty < set[j+1].qty) {
          swap_commodity(set[j],set[j+1]);
        }
      }
    }
  }
  // low to high
  else if (choice == 4) {
    cout << "All items from low to high quantity:\n";
    for (int i=1; i<count; i++) {
      for (int j=0; j<(count-1); j++) {
        if (set[j].qty > set[j+1].qty) {
          swap_commodity(set[j],set[j+1]);
        }
      }
    }
  }
  //clear dynamically allocated memory to prevent memory leak and prints sorted list
  for (int i=0; i<count; i++) {
    print_item(&set[i]);
  }
  delete[] set;
}
