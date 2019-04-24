// find() will be a shared function used by delete, search, and edit in order to
// know what file they're looking for.
#include <iostream>
#include <string>
using namespace std;

commodity* find(commodity* &head) {
  cout << "Would you like to search by name or manufacturer?\n";
  string userin;
  cin >> userin;
   
  // step 1, check if item exists
  item_exists(head, target);
}
