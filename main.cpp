// main but designed by me lmfao
#include <iostream>
#include <string>
using namespace std;

/*
Program Features:
- search commodities
- insert new commodity
- delete obsolete commodities
- update commodity information (allow multipele)
- automatic change of inventory status
- deliver alerts when commodity is out of stock (error handling for too much minus)
- overflow alerts?
- stats on rate of consumption?
*/

// Struct used to hold details of all commodities.
struct commodity {
  string name; // name of commodity
  int qty; // good quantity
} ;

void intro(int x);

// Displays all available commands to the user.
void options() {
  cout << "Available commands are:\nsearch, insert, delete, \n"
  "display, options, help, exit." << endl << endl;
}

// Makes the input string all lowercase characters
// Error handling in case of wrong user input
void lowercase(string &str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
}

int main() {
  string option;
  intro(0);

  while (getline(cin,option)) {
    lowercase(option);
    cout << option << endl;
    if (option == "options") {
      cout << endl;
      options();
    }
    else if (option == "help") {
      cout << "Which option would you like further details on?" << endl;
      cin >> option;
      lowercase(option);
      help(option);
      continue;
    }
    //rest of the functions insert here

    else if (option == "exit") {
      cout << endl << "// Thank you for using the program, this program has now ended. //" << endl;
      break;
    }
    intro(1);
  }

  return 0;
}
