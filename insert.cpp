// NEEDS TO BE REVAMPED, give error message and error processing at the end, return NULL if user decides
// to abandon process.
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
      return false;
    }
  }
  return true;
}

commodity insert(commodity* &head) {
  commodity new_item;
  string str_input;

  cout << "A new item will be entered into the system. Please provide the required details.\n"
  "If the manufacturer is unavailable, please enter \"-\"." << endl;
  cout << "NAME: ";

  getline(cin,str_input);
  str_input = lowercase(fill_spaces(str_input)); // function to fill any spaces with '_', probably will be used elsewhere in the program for searches and such

  while (item_exists(head, str_input)) {
    cout << "This name already exists in the system. Please enter a different name. If you would like to cancel this addition, enter \"-\"\nNAME: ";
    getline(cin,str_input);
    str_input = fill_spaces(str_input);
    if (str_input == "-") {
      cout << "New addition cancelled." << endl;
      return new_item;
    }
  }
  new_item.name = str_input;

  cout << "MANUFACTURER: ";
  getline(cin,str_input);
  fill_spaces(str_input);
  if (str_input == "-") {
    new_item.manuf = "[n/a]]";
  }
  else {
    new_item.manuf = str_input;
  }

// error handling if user inputs words instead of numbers
  cout << "QUANTITY: ";
  cin >> str_input; // no need for getline because no spaces for an int
  while (digit_check(str_input)==false) {
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
