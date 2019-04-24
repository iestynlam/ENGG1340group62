#include <iostream>
#include <string>
using namespace std;

const string filename = "inventory.txt";

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
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;

// INTRODUCTORY MESSAGE & MESSAGES INDICATING USER CAN PROCEED
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
void help(string str);

// Displays all available commands to the user.
void options() {
  cout << "Available commands are:\nsearch, insert, delete, "
  "edit, display, options, help, exit." << endl << endl;
}

// Makes the input string all lowercase characters
// Error handling in case of incorrect user input
void lowercase(string &str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
}

// INPUT : array of commodity structs, number of elements in the array
// OUTPUT : Prints out the commodities in order with accompanying details
// Purpose : used to output arrays of items to the screen for the user to see
void out_array(commodity a[], int n);

// clears any dynamically allocated memory before ending the program to prevent memory leak
void end_program();

// RETURN: A commodity struct with name, manufacturer, and quantity.
commodity insert();

/* Using file I/O and a reference to a 'inventory.txt' to keep track of all items even when program has been terminated
This program opens the file (or creates a new one if it doesnt exist) and creates a linked list which will be used whilst
the program runs.*/
void initialize_list(commodity* &head,string filename);

void append_commodity(commodity* &head, str name, str manuf, int qty);

int main() {
  commodity* head = NULL;
  //initialize_list(head,filename);

  string option;
  intro(0);

// While loop to take in user input until program end
  while (getline(cin,option)) {
    lowercase(option);
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
    else if (option == "search") {
      // give parameters for what can be searched for - name/manuf/qty
      // error handling for user input on search (for strings only)
      // qty search is in-stock/out of stock (remember to do lowercase)
      // pass dynamically allocated array to out_array
    }
    else if (option == "display") {
      // prompt user to ask what they want to sort by - last updated (? might be difficult),
      // quantity, alphabetical name, alphabetical manufacturer
      // pass a dynamically allocated array to out_array
    }
    else if (option == "edit") {
      // search for item and get pointer to the desired item - needs ERROR HANDLING
      // print out current values
      // asks what values to change, '-' for unchanged
    }
    else if (option == "insert") {
      commodity new_item = insert(); // INSERT TO BE IMPLEMENTED, ERROR HANDLING IF ITEM ALREADY EXISTS
      if (new_item.name != "") { // EMPTY STRING RETURNED IF THE PROCESS IS CANCELLED
        append_item(head, new_item.name, new_item.manuf, new_item.qty);  // APPEND_ITEM TO BE IMPLEMENTED
      }
    }
    else if (option == "delete") {
      // search for item - error handling
      // final promt (Y/N) - then "this item has been deleted".
    }

    else if (option == "exit") {
      cout << endl << "// Thank you for using the program, this program has now ended. //" << endl;
      end_program(); // TO BE IMPLEMENTED
      break;
    }
    intro(1);
  }

  return 0;
}
