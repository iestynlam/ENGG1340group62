// only to be used within the system, has no error handling for user input
// Can be used when: Only ONE item in linked list matches the EXACT name

commodity* s_find_by_name(commodity* &head, string target) {
  commodity* current = head;
  while(current->next!=NULL) {
    if (lowercase(current->name)==target) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}
