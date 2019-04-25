// reads user input to determine by name or manufacturer or qty status
// prints items that match query to screen
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
