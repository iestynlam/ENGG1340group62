// Used to print everything in the linked list, used to display to screen for different options
// mostly here for testing whilst writing code

void print_list(commodity* &head) {
  commodity* current= head;
  while (current!=NULL) {
    print_item(current);
    current = current->next;
  }
}
