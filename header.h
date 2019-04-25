#include <fstream>
#include <cmath>
#include "fill_spaces.h"
#include "item_exists.h"
#include "s_find_by_name.h"
#include "update_file.h"
#include "print_item.h"
using namespace std;

/*
struct commodity {
  string name; // name of commodity
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;
*/
const string filename = "inventory.txt";
const string old_filename = "old_inventory.txt";

void append_item(commodity* &head, string name, string manuf, int qty);

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

/*
- clears 'old_inventory.txt'
- copies 'inventory.txt' into 'old_inventory.txt'
- clears 'inventory.txt'
- writes linked list into 'inventory.txt'
- clear linked list to clean up memory
*/
void end_program(commodity* &head) {
  // copy pasting inventory into old_inventory
  ifstream fin (filename);
  ofstream fout_0 (old_filename);
  string line;
  while (getline(fin,line)) {
    fout_0 << line << endl;
  }
  fin.close();
  fout_0.close();
  // printing linked list into 'inventory.tct'
  ofstream fout_1 (filename);
  commodity* current= head;
  while (current!=NULL) {
    fout_1 << current->name << " " << current->manuf << " " << current->qty << endl;
    current = current->next;
  }
  fout_1.close();

  // cleaning up memory - not certain if this is working [needs checking]
  current = head;
  //loops until only the head is left
  while (current->next!=NULL) {
    //loop until the last item in linked list
    while (current->next!=NULL) {
      current = current->next;
    }
    // deletes item
    delete current;
  }
  delete head;
}

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

void initialize_list(commodity* &head, string filename) {
  int count=0;
  commodity item;
  string line;
  ifstream fin0 (filename);
  // count how many line are in the file so it knows how many times to loop,
  // there's probably a better way to do this but it works at least
  while (getline(fin0,line)) {
    count++;
  }
  fin0.close();

  ifstream fin1;
  fin1.open(filename);
  for (int i = 0; i<count; i++) {
    fin1 >> item.name >> item.manuf >> item.qty;
    append_item(head, item.name, item.manuf, item.qty);
  }
  fin1.close();
} // void initialize_list //

void append_item(commodity* &head, string name, string manuf, int qty) {
  commodity* a = new commodity;
  a->name = name;
  a->manuf = manuf;
  a->qty = qty;
  a->next = NULL;

  if (head==NULL) {
    head = a;
  }
  else {
    commodity* cursor = head;
    while (cursor->next!=NULL) {
      cursor = cursor->next;
    }
    cursor->next = a;
  }
}

commodity* find_by_name(commodity* &head) {
  string userin, target;
  while (userin.length()==0) {
    getline(cin,userin);
  }
  target = fill_spaces(lowercase(userin));

  //loop through linked list to find number of matching item(s)
  int count = 0, substr_no = 0;
  commodity* current = head;
  while(current->next!=NULL) {
  // partial name input error handling, multiple items with same name
    if (lowercase(current->name)==target) {
      count++;
    }
    else if (lowercase(current->name).find(target) != -1) {
      substr_no++;
    }
    current = current->next;
  }
  if (lowercase(current->name)==userin) {
    count++;
  }
  else if (lowercase(current->name).find(userin) != -1) {
    substr_no++;
  }
  current = current->next;

  //case of no matches
  if (count == 0 && substr_no == 0) {
    cout << "No items matching \"" << userin << "\" were found.\n";
    return NULL;
  }
  //case of single perfect match, no substrings
  else if (count == 1 && substr_no == 0) {
    return s_find_by_name(head, target);
  }
  //any form of multiple results- THIS IS REALLY BROKEN
  else {
    int n = count+substr_no;
    // dynamically allocated set being declared
    commodity* set = new commodity [n];
    // looping through again and inputting any matching values into the set
    current = head;
    count = 0;

    while(current->next!=NULL) {
      if(lowercase(current->name).find(target) != -1) {
        set[count] = *current;
        count++;
      }
      current = current->next;
    }
    if(lowercase(current->name).find(target) != -1) {
      set[count] = *current;
      count++;
    }

    cout << "These matches were found for \"" << userin << "\". Please indicate the appropriate item via its number.\n";
    for (int i = 0; i<n; i++) {
      // right now i can't get this to work with print_item, so lack of modularity here
      cout << i+1 << ". NAME: " << set[i].name << "\tMANUFACTURER: " << set[i].manuf << "\tQUANTITY: " << set[i].qty << endl;
    }
    cout << "Your choice: ";

    int choice;
    cin >> choice;

    current = &set[choice -1];
    free(set);
    //free should supposedly free any allocated memory
    return current;
  } // any form of multiple results
}

void edit_item(commodity* &target) {
  cout << "Current Data:" << endl;
  print_item(target);
  cout << "Indicate which field should be changed via corresponding number."
  "\n1. Change name\n2. Change manufacturer\n3. Increase quantity\n4. Decrease quantity"
  "\n5. Set quantity\n6. Cancel" << endl;
  int choice;
  cin>> choice;
  if (choice == 1) {
    cout << "Enter new name: ";
    string userin;
    while (userin.length()==0) { //bypass the problem of getline taking new line
      getline(cin,userin);
    }
    target->name = fill_spaces(userin);
  }
  else if (choice == 2) {
    cout << "Enter new manufacturer: ";
    string userin;
    while (userin.length()==0) { //bypass the problem of getline taking new line
      getline(cin,userin);
    }
    target->manuf = fill_spaces(userin);
  }
  else if (choice == 3) {
    cout << "Enter amount to increase by: ";
    int x;
    cin >> x;
    target->qty+=x;
  }
  else if (choice == 4) {
    cout << "Enter amount to decrease by: ";
    int x;
    cin >> x;
    target->qty-=x;
  }
  else if (choice == 5) {
    cout << "Set new quantity: ";
    // maybe put a digit check? i dunno
    int x;
    cin >> x;
    target->qty=x;
  }
  else if (choice == 6) {
    cout << "Action canclled.\n";
  }
}

void remove(commodity* &head, commodity* target) {
  // create two pointer pointing to the previous commodity and after one
  // Previous one => search from head
  commodity* search = new commodity;
  search = head;
  commodity* previous = NULL;
  commodity* after = NULL;
  commodity* tail = NULL;

  //Finding tail
  while (search -> next != NULL){
    search = search -> next;
  }
  tail = search;

  // CASE1 : for removing first item
  search = head;
  if (search -> name == target -> name){
    head = head -> next;
  }
  // Connecting the head to the second item (second item becomes head) and update the file

  // CASE2 : for removing middle item or last item (TESTED)
  else {
    // FINDING PREVIOUS
    while (search -> next -> name != target -> name){ // (Actually I trying to use condition (search->next != target) but fail)
      search = search -> next;
    }
    previous = search;
    // FIND "AFTER" IF TARGET IS NOT at the end

    // CASE2A : for removing the last one
    // if target is at the end => previous -> next = NULL;
    if (tail -> name == target -> name){
      previous -> next = NULL;
    }
    // CASE2B : for removing any other
    else {
      after = target -> next;
      previous -> next = after;
    }
  }

  //PRINT list
  commodity* current= head;
  while (current!=NULL) {
    print_item(current);
    current = current->next;
  }
  update_file(head, filename);
}
// After removal need to update the inventory.txt
