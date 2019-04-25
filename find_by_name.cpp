// This program loops through the linked list to find an item by name, and has error handling in the case of two items having
// the same name but different manufacturer. Also handles the cases of substrings appearing.

// problems with returend pointer when choosing between values?

//DEPENDENCIES OF find_by_name
commodity* s_find_by_name(commodity* &head, string target);
string fill_spaces(string str);
string lowercase(string str);

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
