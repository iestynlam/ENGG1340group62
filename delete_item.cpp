// NOT CURRENTLY WORKING

//deletes an item from the linked list and links the list back together without the items
//also frees memory


void delete_item(commodity* &head, commodity* &target) {
  commodity* current = head;
  // needs if cases if commodity is head or tail.
  if (head->next == target->next) {
    cout << "here we are\n";
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
