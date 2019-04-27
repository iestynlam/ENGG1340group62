#include <iostream>
#include <string>
#include "all_functions.h"
using namespace std;

const string filename = "inventory.txt";
const string inventory_history = "inventory_history.txt";

/*
Program Features:
- search commodities
- insert new commodity
- delete obsolete commodities
- update commodity information
- automatic change of inventory status
- deliver alerts when commodity is out of stock
- display inventory history
*/


// INTRODUCTORY MESSAGE & MESSAGES INDICATING USER CAN PROCEED
void intro(int x);
// INPUT : A command the user wishes to inquire further about
// OUTPUT : Gives further detail on the function and input style of the command.
void help(string str);
// Displays all available commands to the user.
void options();
// INPUT: String of any length
// RETURN: String with all alphabetical characters converted into lowercase
// Error handling in case of variance in user input
string lowercase(string str);
// clears any dynamically allocated memory before ending the program to prevent memory leak
void end_program(commodity* &head);
// INPUT: head of the linked list to be able to check if item already exists
// RETURN: A commodity struct with name, manufacturer, and quantity.
void insert(commodity* &head);
/* Using file I/O and a reference to a 'inventory.txt' to keep track of all items even when program has been terminated
This program opens the file (or creates a new one if it doesnt exist) and creates a linked list which will be used whilst
the program runs.*/
void initialize_list(commodity* &head,string filename);
// INPUT: pointer to the head
// RETURN: A pointer to a specified commodity, namely, with the specified name
commodity* find_by_name(commodity* &head);
// takes pointer to target and edits details
void edit_item(commodity* &target);
// removes target item from linked list
void remove(commodity* &head, commodity* &target);
// searches for item based on criteria
void search_item(commodity* &head);
// displays items according to order selected by user
void display(commodity* &head);
// writes items to inventory history
void before_end_program(commodity* head);
// shows history of inventory
void history(string inventory_history);

int main() {
  commodity* head = NULL;
  initialize_list(head,filename);

  string option, userin;
  intro(0);

// While loop to take in user input until program end
  while (true) {
    while (userin.length()==0){
      getline(cin,userin);
    }
    option = lowercase(userin);
    // separate userin and option so that error messages match case with input
    if (option == "options") {
      cout << endl;
      options();
    }
    else if (option == "help") {
      cout << "Which option would you like further details on?" << endl;
      cin >> userin;
      help(userin);
    }
    else if (option == "search") {
      search_item(head);
    }
    else if (option == "display") {
      display(head);
    }
    else if (option == "edit") {
      cout << "Please enter the name of the item you wish to edit.\n";
      commodity* target = find_by_name(head);
      if (target!=NULL) {
        edit_item(target);
      }
    }
    else if (option == "insert") {
      insert(head); // INSERT TO BE IMPLEMENTED
    }
    else if (option == "delete") {
      cout << "Please enter the name of the item you wish to delete.\n";
      commodity* target = find_by_name(head);
      if (target!=NULL) {
        cout << "Are you sure you wish to delete the item: " << target->name << "? (Y/N)\n";
        string confirm, temp = target->name;
        cin >> confirm;
        if (lowercase(confirm)=="y") {
          remove(head, target);
          cout << "The item \"" << temp << "\" has been deleted.\n";
        }
        else {
          cout << "Action not executed.\n";
        }
      }
      // final prompt (Y/N) - then "this item has been deleted".
    }
    else if (option == "exit") {
      cout << endl << "// Thank you for using the program, this program has now ended. //" << endl;
      before_end_program(head);
      end_program(head);
      break;
    }
    // Display the content of inventory_history.txt
    else if (option == "history"){
      history(inventory_history);
    }
    else {
      cout << userin << " is not an available command. Type 'options' to view the available commands.\n";
    }
    intro(1);
    userin = "";
  }

  return 0;
}
