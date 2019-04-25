// stores all the information of the various commands in the program

#include "lowercase.h"
using namespace std;

void help(string userin) {
  string str = lowercase(userin);
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
    cout << "Terminates the program.";
  }
  else if (str == "edit") {
    cout << "Edit details of an existing commodity. Allows you to change item name, manufacturer, and add/decrease/set quantity.";
  }
  else if (str == "display") {
    cout << "Displays all items currently in the system, along with" <<
    " associated information.";
  }
  else if (str == "help") {
    cout << "Provides further details on the functions of available commands.";
  }
  else {
    cout << userin << " is not an available command. Type 'options' to view the available commands.";
  }
  cout << endl;
}
