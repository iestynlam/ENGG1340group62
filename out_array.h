/* This function is used to print out an array passed into it onto the screen along with the related data of the commodity. This
function will be used to output most info to the screen, e.g. sort functions, search functions, etc*/
using namespace std;
// FIX : spacing error if one name/manuf is too long, maybe display using new lines?

// TO BE FIX

struct commodity {
  string name; // name of commodity
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;

void out_array(commodity a[], int n) {
  for (int i = 0; i < a.size(); i++) {
    cout << "NAME: " << a[i].name << "\tMANUFACTURER: " << a[i].manuf <<
    "\tQUANTITY: " << a[i].qty << endl;
  }
}
