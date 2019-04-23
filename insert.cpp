// reads user input and passes it to a commodity type struct to be appended to the linked list
// error handling if item already exists or if invalid input for qty field
// TO DO : insert an escape if the user no longer wishes to enter a new item.
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* checks if all characters are digits to ensure input is an int. Returns true if not all
characters are digits and the main insert command prompts users to reenter a valid input.*/
bool digit_check(string str_input) {
  for (int i = 0; i < str_input.length() ; i++) {
    if (isdigit(str_input[i]) == false) {
      cout << "Only integers can be entered for this field. Please enter a valid input." << endl;
      return true;
    }
  }
  return false;
}

commodity insert(commodity* &head) {
  commodity new_item;
  string str_input;

  cout << "A new item will be entered into the system. Please provide the required details.\n"
  "If the manufacturer is unavailable, please enter \"0\"." << endl;
  cout << "NAME: ";

  cin >> str_input;
  while (item_exists(head, str_input)) {
    cout << "This name already exists in the system. Please enter a different name.\nNAME: "
    cin >> str_input;
  }
  new_item.name = str_input;

  cout << "MANUFACTURER: ";
  cin >> str_input;
  if (str_input == "0") {
    new_item.manuf = "[n/a]]";
  }
  else {
    new_item.manuf = str_input;
  }

// error handling if user inputs words instead of numbers
  cout << "QUANTITY: ";
  cin >> str_input;
  while (digit_check(str_input)) {
    cout << "QUANTITY: ";
    cin >> str_input;
  }
  // converting string back into integer
  int temp=0;
  for (int i = 0; i < str_input.length(); i++) {
    temp+=(int(str_input[i])-48)*pow(10,(str_input.length()-i-1));
  }
  new_item.qty = temp;

  return new_item;
}
