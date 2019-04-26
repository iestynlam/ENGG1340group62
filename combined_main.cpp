#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

const string filename = "inventory.txt";
const string old_filename = "old_inventory.txt";

struct commodity {
  string name; // name of commodity
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;

void print_item(commodity* item) {
  cout << "NAME: " << item->name << "\tMANUFACTURER: " << item->manuf << "\tQUANTITY: " << item->qty << endl;
}

void print_list(commodity* &head) {
  commodity* current= head;
  while (current!=NULL) {
    print_item(current);
    current = current->next;
  }
}

void intro(int x) {
  if (x == 0) { // first intro message
    cout << "// Welcome to the commodity manager! //" << endl << "\nType \"options\" to view available "
    "actions and \"help\" for further details regarding available options. Type \"exit\" "
    "to shut down the program." << endl;
  }
  cout << endl << "PLEASE INPUT YOUR SELECTED OPTION TO PROCEED: " << endl;
}

string lowercase(string userin);

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
    cout << "Displays all items currently in the system, along with"
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

void options() {
  cout << "Available commands are:\nsearch, insert, delete, "
  "edit, display, options, help, exit." << endl << endl;
}

string fill_spaces(string str) {
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      str.replace(i,1,"_");
    }
  }
  return str;
}

string lowercase(string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}

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
  fin1.close();} // void initialize_list //

commodity* s_find_by_name(commodity* &head, string target) {
  commodity* current = head;
  while(current!=NULL) {
    if (lowercase(current->name)==target) {
      return current;
    }
    current = current->next;
  }
  return NULL;
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
  while(current!=NULL) {
  // partial name input error handling, multiple items with same name
    if (lowercase(current->name)==target) {
      count++;
    }
    else if (lowercase(current->name).find(target) != -1) {
      substr_no++;
    }
    current = current->next;
  }

  //case of no matches
  if (count == 0 && substr_no == 0) {
    cout << "No items matching \"" << userin << "\" were found.\n";
    return NULL;
  }
  //case of single perfect match, no substrings
  else if (count == 1 && substr_no == 0) {
    return s_find_by_name(head, target);
  }
  else {
    int n = count+substr_no;
    // dynamically allocated set being declared
    commodity* set = new commodity [n];
    // looping through again and inputting any matching values into the set
    current = head;
    count = 0;

    while(current!=NULL) {
      if(lowercase(current->name).find(target) != -1) {
        set[count] = *current;
        count++;
      }
      current = current->next;
    }

    cout << "These matches were found for \"" << userin << "\". Please indicate the appropriate item via its number.\n";
    for (int i = 0; i<n; i++) {
      // right now i can't get this to work with print_item, so lack of modularity here
      cout << i+1 << ". NAME: " << set[i].name << "\tMANUFACTURER: " << set[i].manuf << "\tQUANTITY: " << set[i].qty << endl;
    }
    cout << "Your choice: ";

    int choice;
    cin >> choice;

    // loops through to not return the copy but the original item in the linked list
    current = &set[choice -1];
    commodity* current2 = head;
    while(current2!=NULL) {
      if (current2->name==current->name && current2->manuf==current->manuf && current2->qty==current->qty) {
        delete[] set;
        return current2;
      }
      current2 = current2->next;
    }
  } // any form of multiple results
  return NULL;
}

void search_item(commodity* &head) {
  commodity* current = head;
  cout << "Select what criteria to search by:\n1. Name\n2. Manufacturer\n3. In stock\n4. Out of stock\n";
  int choice;
  cin >> choice;
  // name
  if (choice == 1) {
    cout << "Please enter item name.\n";
    string userin, target;
    while (userin.length()==0) {
      getline(cin,userin);
    }
    target = fill_spaces(lowercase(userin));
    cout << "These matches were found for \"" << userin << "\".\n";
    while(current!=NULL) {
      if (lowercase(current->name).find(target) != -1) {
        print_item(current);
      }
      current = current->next;
    }
  }
  // manuf
  else if (choice == 2) {
    cout << "Please enter manufacturer name.\n";
    string userin, target;
    while (userin.length()==0) {
      getline(cin,userin);
    }
    target = fill_spaces(lowercase(userin));
    cout << "These matches were found for \"" << userin << "\".\n";
    while(current!=NULL) {
      if (lowercase(current->manuf).find(target) != -1) {
        print_item(current);
      }
      current = current->next;
    }
  }
  // in stock
  else if (choice == 3) {
    cout << "The following items are in stock:\n";
    while (current!=NULL) {
      if (current->qty>0) {
        print_item(current);
      }
      current = current->next;
    }
  }
  // out of stock
  else if (choice == 4) {
    cout << "The following items are out of stock:\n";
    while (current!=NULL) {
      if (current->qty==0) {
        print_item(current);
      }
      current = current->next;
    }
  }
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

void swap_commodity(commodity &a, commodity &b) {
  commodity temp;
  temp = a;
  a = b;
  b = temp;
}

void display(commodity* &head) {
  commodity* current = head;
  cout << "Select order to display in:\n1. Alphabetical (Name)\n2. Alphabetical (Manufacturer)"
  "\n3. High to low quantity\n4. Low to high quantity\n";

  int choice,count=0;
  //convert linked list into a dynamically allocated array to be sorted later
  while (current!=NULL) {
    count++;
    current = current->next;
  }
  commodity* set = new commodity[count];
  current = head;
  for (int i=0;i<count;i++) {
    set[i] = *current;
    current = current->next;
  }
  cin >> choice;
  // name
  if (choice == 1) {
    cout << "All items in alphabetical order (by name):\n";
    for (int i=1; i<count; i++) {
      for (int j=0; j<(count-1); j++) {
        if (set[j].name > set[j+1].name) {
          swap_commodity(set[j],set[j+1]);
        }
      }
    }
  }
  // manuf
  else if (choice == 2) {
    cout << "All items in alphabetical order (by manufacturer):\n";
    for (int i=1; i<count; i++) {
      for (int j=0; j<(count-1); j++) {
        if (set[j].manuf > set[j+1].manuf) {
          swap_commodity(set[j],set[j+1]);
        }
      }
    }
  }
  // high to low
  else if (choice == 3) {
    cout << "All items from high to low quantity:\n";
    for (int i=1; i<count; i++) {
      for (int j=0; j<(count-1); j++) {
        if (set[j].qty < set[j+1].qty) {
          swap_commodity(set[j],set[j+1]);
        }
      }
    }
  }
  // low to high
  else if (choice == 4) {
    cout << "All items from low to high quantity:\n";
    for (int i=1; i<count; i++) {
      for (int j=0; j<(count-1); j++) {
        if (set[j].qty > set[j+1].qty) {
          swap_commodity(set[j],set[j+1]);
        }
      }
    }
  }
  //clear dynamically allocated memory and output results
  cout << endl;
  for (int i=0; i<count; i++) {
    print_item(&set[i]);
  }
  delete[] set;
}

bool digit_check(string str_input) {
  for (int i = 0; i < str_input.length() ; i++) {
    if (isdigit(str_input[i]) == false) {
      cout << "Only integers can be entered for this field. Please enter a valid input." << endl;
      return false;
    }
  }
  return true;
}

void insert(commodity* &head) {
  commodity new_item;
  string item_name,item_manuf,str_input;

  cout << "A new item will be entered into the system. Please provide the required details.\n"
  "If the manufacturer is unavailable, please enter \"-\"." << endl;

  cout << "NAME: ";
  while (item_name.length()==0) {
    getline(cin,item_name);
  }
  item_name = lowercase(fill_spaces(item_name)); // function to fill any spaces with '_', probably will be used elsewhere in the program for searches and such
  new_item.name = item_name;

  cout << "MANUFACTURER: ";
  while (item_manuf.length()==0) {
    getline(cin,item_manuf);
  }
  item_manuf = lowercase(fill_spaces(item_manuf));
  if (item_manuf == "-") {
    new_item.manuf = "[n/a]";
  }
  else {
    new_item.manuf = item_manuf;
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

  //CHECK IF ITEM ALREADY EXISTS
  commodity* current = head;
  bool exists = false;
  while(current!=NULL) {
    if (lowercase(current->name) == new_item.name && current->manuf == new_item.manuf) {
      cout << "An item already exists in the system with the same name and manufacturer:\n";
      print_item(current);
      cout << "What would you like to do?\n1. Merge items\n2. Change name\n3. Change manufactuer\n4. Cancel\n";
      int choice;
      cin >> choice;

      if (choice == 1) {
        current->qty+=new_item.qty;
        exists = true;
        break;
      }

      else if (choice == 2) {
        item_name = "";
        cout << "NAME: ";
        while (item_name.length()==0) {
          getline(cin,item_name);
          if (lowercase(fill_spaces(item_name)) == lowercase(current->name)) {
              cout << "Please use a different name.\n";
              item_name = "";
            }
        }
        item_name = lowercase(fill_spaces(item_name)); // function to fill any spaces with '_', probably will be used elsewhere in the program for searches and such
        new_item.name = item_name;
        append_item(head, new_item.name, new_item.manuf, new_item.qty);
        exists = true;
        break;
      }

      else if (choice == 3) {
        item_manuf="";
        cout << "MANUFACTURER: ";
        while (item_manuf.length()==0) {
          getline(cin,item_manuf);
          item_manuf = lowercase(fill_spaces(item_manuf));
          if (item_manuf == "-") {
            new_item.manuf = "[n/a]";
          }
          else {
            new_item.manuf = item_manuf;
          }
          if (lowercase(fill_spaces(item_manuf)) == lowercase(current->manuf)) {
              cout << "Please use a different name.\n";
              item_manuf = "";
            }
          }
        append_item(head, new_item.name, new_item.manuf, new_item.qty);
        exists = true;
        break;
      }

      else if (choice == 4) {
        cout << "Action cancelled.";
        exists = true;
        break;
      }
    }
    current = current->next;
  }
  if (exists==false) {
    append_item(head, new_item.name, new_item.manuf, new_item.qty);
  }
}

void update_file(commodity* &head, string filename);

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
  if ((search -> name == target -> name) && (search -> manuf == target -> manuf)){
    head = head -> next;
  }
  // Connecting the head to the second item (second item becomes head) and update the file

  // CASE2 : for removing middle item or last item (TESTED)
  else {
    // FINDING PREVIOUS
    while ((search -> next -> name != target -> name) || (search -> next -> manuf != search -> manuf)){
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
}

void update_file(commodity* &head, string filename) {
  ofstream ostream;
  string line;
  commodity* &current = head;
  ostream.open(filename);
  while (current -> next != NULL){
    ostream << current -> name << ' ' << current -> manuf << ' ' << current -> qty << endl;
    current = current -> next;
  }
  ostream << current -> name << ' ' << current -> manuf << ' ' << current -> qty;
  ostream.close();
}

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
  if (head->next==NULL) {
    delete head;
  }

  while (current->next!=NULL) {
    head = head->next;
    delete current;
    current = head;
  }
}

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
      continue;
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
          cout << "The item \"" << temp << "\" has been deleted.";
        }
        else {
          cout << "Action not executed.\n";
        }
      }
      // final promt (Y/N) - then "this item has been deleted".
    }
    else if (option == "exit") {
      cout << endl << "// Thank you for using the program, this program has now ended. //" << endl;
      end_program(head); // TO BE IMPLEMENTED
      break;
    }
    else {
      cout << userin << " is not an available command. Type 'options' to view the available commands.\n";
    }
    intro(1);
    userin = "";
  }

  return 0;
}
