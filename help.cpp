#include <iostream>
#include <string>
using namespace std;

void help(string str) {
  if (str == "options") {
    cout << "Used to view all available user commands.";
  }
  else if (str == "search") {
    cout << "Used to search for commodities according to specific filters." << endl
    << "Available filters are:" << endl << "filter 1, filter 2, etc";
  }
  else if (str == "insert") {
    cout << "Used to insert a new commodity into the program.";
  }
  else if (str == "delete") {
    cout << "To delete a commodity from the program.";
  }
  else if (str == "exit") {
    cout << "Terminates the program."
  }
  else if (str == "display") {
    cout << "Displays all items currently in the system, along with"
    " associated information."
  }
  else if (str == "help") {
    cout << "Provides further details on the functions of available commands."
  }
  else {
    cout << str << " is not a valid command.";
  }
  cout << endl;
}
