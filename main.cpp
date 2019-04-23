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

void intro(int x) {
  if (x == 0) { // first intro message
    cout << "// Welcome to the commodity manager! //" << endl << "\nType \"options\" to view available "
    "actions and \"help\" for further details regarding available options. Type \"exit\" "
    "to shut down the program." << endl;
  }
  cout << endl << "PLEASE INPUT YOUR SELECTED OPTION TO PROCEED: " << endl;
}

// INPUT : A command the user wishes to inquire further about
// OUTPUT : Gives further detail on the function and input style of the command.
void help(string str) {
  if (str == "options") {
    cout << "To view all available user commands.";
  }
  else if (str == "search") {
    cout << "Used to search for commodities according to specific filters." << endl
    << "Available filters are:" << endl << "filter 1, filter 2, etc";
  }
  else if (str == "insert") {
    cout << "To insert a new commodity into the program.";
  }
  else if (str == "delete") {
    cout << "To delete a commodity from the program.";
  }
  else if (str == "exit") {
    cout << "Terminates the program.";
  }
  else if (str == "display") {
    cout << "Displays all items currently in the system, along with"
    " associated information.";
  }
  else if (str == "help") {
    cout << "Provides further details on the functions of available commands.";
  }
  else {
    cout << str << " is not a valid command.";
  }
  cout << endl;
}
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
