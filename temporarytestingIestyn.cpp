#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string filename = "inventory.txt";

// Struct used to hold details of all commodities. [FOR REFERENCE]
// Not sure if this is actually necessary if its all compiled together
struct commodity {
  string name; // name of commodity
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;

void delete_item(commodity* &head, commodity* &target) {
  commodity* current = head;
  // needs if cases if commodity is head or tail.
  if (head->next == target->next) {
    head = head->next;
    current = NULL;
    delete current;
  }
  else {
    while(current->next!=target) {
      current = current->next;
    }
    cout << current->name << " beforehand\n";
    current->next = target->next;
    target = NULL;
    delete target;
  }
}

// only to be used within the system, has no error handling for user input
// Can be used when: Only ONE item in linked list matches the EXACT name
commodity* s_find_by_name(commodity* &head, string target) {
  commodity* current = head;
  while(current!=NULL) {
    if (current->name==target) {
      return current;
    }
    current = current->next;
  }
  return NULL;
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

void print_item(commodity* item);

void print_list(commodity* &head) {
  commodity* current= head;
  while (current!=NULL) {
    print_item(current);
    current = current->next;
  }
}

void print_item(commodity* item) {
  cout << "NAME: " << item->name << "\tMANUFACTURER: " << item->manuf << "\tQUANTITY: " << item->qty << endl;
}

commodity* find_by_name(commodity* &head) {
  string userin, target;
  cout << endl;
  getline(cin,userin); // User inputs name, can have spaces
  target = fill_spaces(lowercase(userin)); // Fills spaces and makes it all lowercase

  //loop through linked list to find number of matching item(s)
  int count = 0, substr_no = 0;
  commodity* current = head;
  while(current!=NULL) {
  // partial name input error handling, multiple items with same name
    if (current->name==target) {
      count++;
    }
    else if (current->name.find(target) != -1) {
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
  //any form of multiple results- THIS IS REALLY BROKEN
  else {
    int n = count+substr_no;
    // dynamically allocated set being declared
    commodity* set = new commodity [n];
    // looping through again and inputting any matching values into the set
    current = head;
    count = 0;

    while(current!=NULL) {
      if(current->name.find(target) != -1) {
        set[count] = *current;
        count++;
      }
      current = current->next;
    }

    cout << "These matches were found for \"" << userin << "\". Please indicate the appropriate item via its number.\n";
    for (int i = 0; i<n; i++) {
      cout << i+1 << ". NAME: " << set[i].name << "\tMANUFACTURER: " << set[i].manuf << "\tQUANTITY: " << set[i].qty << endl;
    }
    cout << "Your choice: ";

    int choice;
    cin >> choice;
    choice--;

    current = &set[choice];
    free(set);
    //inserting delete[] set here causes issues when selecting first variable? unsure if free works.
    return current;
  } // any form of multiple results
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
  fin1.close();
} // void initialize_list //

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
    while (userin.length()==0) {
      getline(cin,userin);
    }
    target->name = fill_spaces(userin);
  }
  else if (choice == 2) {
    cout << "Enter new manufacturer: ";
    string userin;
    cin >> userin;
    getline(cin,userin);
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

int main() {
  commodity* head = NULL;
  initialize_list(head,filename);
  print_list(head);
  commodity* target = find_by_name(head); // find by name returns wrong pointer?
  print_item(target);
  if (target !=NULL) {
    edit_item(target);
  }
  else {
    cout << "u fucked it" << endl;
  }
  print_list(head);
}
