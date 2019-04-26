// Reads user input for the data needed to add a new commodity into the inventory management system
// Has error-handling in the case that the entered item already exists in the program, and allows users to change their input accordingly
// - justification : one worker may input a new shipment of a new good and find out that someone has already done so, thus they can adjust accordingly

void insert(commodity* &head) {
  commodity new_item;
  string item_name,item_manuf,str_input;

  cout << "A new item will be entered into the system. Please provide the required details.\n"
  "If the manufacturer is unavailable, please enter \"-\"." << endl;

  cout << "NAME: ";
  while (item_name.length()==0) { // prevents the program from using the newline character
    getline(cin,item_name);
  }
  item_name = fill_spaces(item_name); // all names / manufacturers cannot have spaces so fill_spaces handles the potential error
  new_item.name = item_name;

  cout << "MANUFACTURER: ";
  while (item_manuf.length()==0) {
    getline(cin,item_manuf);
  }
  item_manuf = fill_spaces(item_manuf);
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
        cout << "NAME:\n";
        while (item_name.length()==0) {
          getline(cin,item_name);
          if (lowercase(fill_spaces(item_name)) == lowercase(current->name)) {
              cout << "Please use a different name.\n";
              item_name = "";
            }
        }
        item_name = fill_spaces(item_name);
        new_item.name = item_name;
        append_item(head, new_item.name, new_item.manuf, new_item.qty);
        exists = true;
        break;
      }

      else if (choice == 3) {
        item_manuf="";
        cout << "MANUFACTURER:\n";
        while (item_manuf.length()==0) {
          getline(cin,item_manuf);
          item_manuf = fill_spaces(item_manuf);
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
  // if item doesnt already exist
  if (exists==false) {
    append_item(head, new_item.name, new_item.manuf, new_item.qty);
  }
}
