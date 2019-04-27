/* checks if all characters are digits to ensure input is an int. Returns true if not all
characters are digits and the main insert command prompts users to reenter a valid input.*/
#include <string>
#include <iostream>
using namespace std;

bool digit_check(string str_input) {
  for (int i = 0; i < str_input.length() ; i++) {
    if (isdigit(str_input[i]) == false) {
      cout << "Only integers can be entered for this field. Please enter a valid input." << endl;
      return false;
    }
  }
  return true;
}
