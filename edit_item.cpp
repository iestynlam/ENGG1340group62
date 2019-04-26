/* WORKS
displays the current data of the item and provides options for what to change
- add quantity
- subtract quantity
- set quantity
- change name
- change manufacturer
*/

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
    if (target->qty <= 0) {
      cout << "WARNING: Item no longer in stock." << endl;
    }
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
