#include <iostream>
#include <string>
#include "header.h"
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

// INTRODUCTORY MESSAGE & MESSAGES INDICATING USER CAN PROCEED
void intro(int x) {
  if (x == 0) { // first intro message
    cout << "// Welcome to the commodity manager! //" << endl << "\nType \"options\" to view available "
    "actions and \"help\" for further details regarding available options. Type \"exit\" "
    "to shut down the program." << endl;
  }
  cout << endl << "PLEASE INPUT YOUR SELECTED OPTION TO PROCEED: " << endl;
}

// Displays all available commands to the user.
void options() {
  cout << "Available commands are:\nsearch, insert, delete, "
  "edit, display, options, help, exit." << endl << endl;
}

int main() {
  commodity* head = NULL;
  initialize_list(head,filename);

  string option, userin;
  intro(0);

// While loop to take in user input until program end
  while (option != "exit") {
    cin >> userin;
    option = lowercase(userin);
    // separate userin and option so that error messages match case with input
    if (option == "options") {
      cout << endl;
      options();
    }
    else {
      if (option == "help") {
      cout << "Which option would you like further details on?" << endl;
      cin >> userin;
      help(userin);
      intro(1);
      continue;
      }
    else {
      if (option == "search") {
      // give parameters for what can be searched for - name/manuf/qty
      // error handling for user input on search (for strings only)
      // qty search is in-stock/out of stock (remember to do lowercase)
      // pass dynamically allocated array to out_array
      //continue => intro(1)
      }
    else {
      if (option == "display") {
      // prompt user to ask what they want to sort by - last updated (? might be difficult),
      // quantity, alphabetical name, alphabetical manufacturer
      // pass a dynamically allocated array to out_array
      //continue => intro(1)
      }
    else {
      if (option == "edit") {
        cout << "Please enter the name of the item you wish to edit.\n";
        commodity* target = find_by_name(head);
        edit_item(target);
      }
    else {
      if (option == "insert") {
        commodity new_item = insert(head); // INSERT TO BE IMPLEMENTED, ERROR HANDLING IF ITEM ALREADY EXISTS
        if (new_item.name != "") { // EMPTY STRING RETURNED IF THE PROCESS IS CANCELLED
          append_item(head, new_item.name, new_item.manuf, new_item.qty);
      }
      intro(1);
      continue;
    }
    else {
      if (option == "delete") {
        cout << "Please enter the name of the item you wish to delete.\n";
        commodity* target = find_by_name(head);
        cout << "Are you sure you wish to delete the item: " << target->name << "? (Y/N)\n";
        char confirm;
        cin >> confirm;
        if (confirm=='Y') {
          remove(head, target);
          intro(1);
          continue;
        }
        else {
        cout << "Action not executed.\n";
        intro(1);
        continue;
        }
        // final promt (Y/N) - then "this item has been deleted".
      }
    else {
      if (option == "exit") {
        cout << endl << "// Thank you for using the program, this program has now ended. //" << endl;
        end_program(head); // TO BE IMPLEMENTED
        break;
      }
      // If user enter wrong input
      else {
        cout << userin << " is not an available command. Type 'options' to view the available commands.\n";
      }
      intro(1);
  }
}
}
}
}
}
}
}
}
