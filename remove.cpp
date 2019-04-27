// INPUT: A head pointer and a target pointer
// FUNCTIONL: removes target pointer from list and deletes allocated memory, then relinks list

void remove(commodity* &head, commodity* &target) {
  commodity* current = head;
  //if head
  if (head==target) {
    head = head->next;
    delete current;
  }
  else {
    // current becomes the item before target
    while (current->next != target) {
      current = current->next;
    }
    //between and end case
    current->next = target->next;
    delete target;
    }
  }
}
