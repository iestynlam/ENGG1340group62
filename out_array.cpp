/* This function is used to print out an array passed into it onto the screen along with the related data of the commodity. This
function will be used to output most info to the screen, e.g. sort functions, search functions, etc*/

#include <iostream>
#include <string>
using namespace std;

// Struct used to hold details of all commodities. [FOR REFERENCE]
// Not sure if this is actually necessary if its all compiled together
struct commodity {
  string name; // name of commodity
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;

// FIX : spacing error if one name/manuf is too long, maybe display using new lines?
void out_array(commodity a[], int n) {
  for (int i = 0; i < a.size(); i++) {
    cout << "Item: " << a[i].name << "\tManufacturer: " << a[i].manuf <<
    "\tQuantity: " << a[i].qty << endl;
  }
}
