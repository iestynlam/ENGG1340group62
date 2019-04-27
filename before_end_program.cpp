#include <fstream>

void before_end_program(commodity* head){
  //creating a txt file, buffer,  to save the linked list
  ofstream fout_2 (buffer);
  commodity* current1= head;
  while (current1!=NULL) {
    fout_2 << current1->name << " " << current1->manuf << " " << current1->qty << endl;
    current1 = current1->next;
  }
  fout_2.close();
  // if linked list and old_inventory.txt is different
  if (!same(buffer, old_filename)){
    write_history(buffer, inventory_history);
  }
}
