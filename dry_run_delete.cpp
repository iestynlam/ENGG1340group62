#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string filename = "inventory.txt";
struct commodity {
  string name; // name of commodity
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;

void print_item(commodity* item) {
  cout << "NAME: " << item->name << "\tMANUFACTURER: " << item->manuf << "\tQUANTITY: " << item->qty << endl;
}

void append_item(commodity* &head, string name, string manuf, int qty){
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

// This program loops through the linked list to find an item by name, and has error handling in the case of two items having
// the same name but different manufacturer. Also handles the cases of substrings appearing.

// problems with returend pointer when choosing between values?

//DEPENDENCIES OF find_by_name
string lowercase(string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}

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
  string userin;
  cin >> userin; // User inputs name

  //loop through linked list to find number of matching item(s)
  int count = 0, substr_no = 0;
  commodity* current = head;

  while(current->next != NULL) {
  // partial name input error handling, multiple items with same name
    if (lowercase(current->name)==userin) {
      count++;
    }
    else if (lowercase(current->name).find(userin) != -1) {
      substr_no++;
    }
    current = current->next;
  }
  // run again for last one
  if (lowercase(current->name)==userin) {
    count++;
  }
  else if (lowercase(current->name).find(userin) != -1) {
    substr_no++;
  }

  //case of no matches
  if (count == 0 && substr_no == 0) {
    cout << "No items matching \"" << userin << "\" were found.\n";
    return NULL;
  }
  //case of single perfect match, no substrings
  else if (count == 1 && substr_no == 0) {
    return s_find_by_name(head, userin);
  }
  //any form of multiple results
  else {
    int n = count+substr_no;
    cout << n << endl;
    // dynamically allocated set being declared
    commodity* set = new commodity [n];
    // looping through again and inputting any matching values into the set
    current = head;
    count = 0;

    while(current->next != NULL) {
      if(lowercase(current->name).find(userin) != -1) {
        set[count] = *current;
        count++;
      }
      current = current->next;
    }
    // run again for last one
    if(lowercase(current->name).find(userin) != -1) {
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
    current = &set[choice - 1];
    //inserting delete[] set here causes issues when selecting first variable? unsure if free works.
    return current;
  } // any form of multiple results
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

// To update the inventory.txt when called
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

// INPUT: A head pointer and a target pointer
// Remove targeted commodity from list
// And relinked!!
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
  //(search -> name == target -> name) && (search -> manuf == target -> manuf)
  if ((search -> name == target -> name) && (search -> manuf == target -> manuf)){
    head = head -> next;
  }
  // Connecting the head to the second item (second item becomes head) and update the file

  // CASE2 : for removing middle item or last item (TESTED)
  else {
    // FINDING PREVIOUS
    // (((search -> next -> name) != (target -> name)) && ((search -> next -> manuf) != (target -> manuf))
    while ((((search -> next) -> name) != (target -> name)) || (((search -> next) -> manuf) != (target -> manuf))){
      search = search -> next;
    }
    previous = search;

    // CASE2A : for removing the last one
    // if target is at the end => previous -> next = NULL;
    //(tail -> name == target -> name) && (tail -> manuf == target -> manuf)
    if ((tail -> name == target -> name) && (tail -> manuf == target -> manuf)){
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

int main(){
  commodity* head = NULL;
  initialize_list(head, filename);
  commodity* cursor = head;
  commodity* found = NULL;
/*
 //find our target and assign a pointer to our target
  cout << "Type in the name of commodity u wanna find: " << endl;
  commodity* found = new commodity;
  found = find_by_name(head);
  cout << "NAME: " << found->name << "\tMANUFACTURER: " << found->manuf << "\tQUANTITY: " << found->qty << endl;

*/
  //delete the third one az24_x3
  cout << "Type in the name of commodity u wanna delete: " << endl;
  found = find_by_name(head);
  print_item(found);
  cout << endl;
  if (found != NULL){
    remove(head, found);
  }
  // if found == NULL => return option
  // else{}
}
