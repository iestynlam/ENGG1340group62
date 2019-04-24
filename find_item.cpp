// find_item() will be a shared function used by delete, search, and edit in order to
// know what file they're looking for.
#include <iostream>
#include <string>
using namespace std;

commodity* find_item(commodity* &head) {
  // CHECK WHAT CRITERIA TO SEARCH BY
  string userin;
  cout << "Would you like to search by name or manufacturer?\n You may enter N or M.\n";
  while (getline(cin,userin)) {
    string option, target;
    option = lowercase(userin);
    // using find instead of == so that users don't have to type the full thing
    if ("name".find(option) != -1) {
      cout << "Enter name: ";
      cin >> target;
      break;
    }
    else if ("manufacturer".find(option) != -1) {
      cout << "Enter manufacturer: ";
      cin >> target;
      break;
    }
    else {
      cout << "Invalid. Please input N or M.\n";
    }
  }

  // CHECK IF ITEM ITSELF EXISTS, 0=none, 1=one case, 2=same name different manufacturer(s)
  if (item_exists(head, target) == 1) {

  }
}
