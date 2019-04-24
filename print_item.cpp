// prints a single commodity to screen in the desired format

void print_item(commodity* item) {
  cout << "NAME: " << item->name << "\tMANUFACTURER: " << item->manuf << "\tQUANTITY: " << item->qty << endl;
}
