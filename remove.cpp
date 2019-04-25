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
}
// After removal need to update the inventory.txt
