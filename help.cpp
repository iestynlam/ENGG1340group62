// Takes in user input and returns details regarding the specific command.

#include <iostream>
#include <string>
#include "all_functions.h"
using namespace std;

void help(string userin) {
  string str = lowercase(userin);
  if (str == "options") {
    cout << "Used to view all available user commands.";
  }
  else if (str == "search") {
    cout << "Used to search for commodities according to specific filters." << endl
    << "Available filters are:" << endl << "- search by name\n- search by manufacturer\n- search by in stock"
    "\n- search by out of stock\n";
  }
  else if (str == "insert") {
    cout << "Used to insert a new commodity into the program.";
  }
  else if (str == "delete") {
    cout << "To delete a commodity from the program.";
  }
  else if (str == "exit") {
    cout << "Saves all changes to commodities and terminates the program.";
  }
  else if (str == "edit") {
    cout << "Edit details of an existing commodity. Allows you to change item name, manufacturer, and add/decrease/set quantity.";
  }
  else if (str == "display") {
    cout << "Displays all items currently in the system, along with";
    " associated information. Can be displayed by name, name of manufacturer, and increasing/decreasing quantity.";
  }
  else if (str == "help") {
    cout << "Provides further details on the functions of available commands.";
  }
  else if (str == "history"){
    cout << "Display the history of inventory storage.";
  }
  else {
    cout << userin << " is not an available command. Type 'options' to view the available commands.";
  }
  cout << endl;
}
