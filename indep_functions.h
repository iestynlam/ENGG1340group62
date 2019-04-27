#ifndef INDEP_FUNCTIONS_H
#define INDEP_FUNCTIONS_H

void print_item(commodity* item);
void intro(int x);
string lowercase(string str);
string fill_spaces(string str);
void help(string userin);
void options();
void append_item(commodity* &head, string name, string manuf, int qty);
void end_program(commodity* &head);
void swap_commodity(commodity &a, commodity &b);
bool digit_check(string str_input);
void remove(commodity* &head, commodity* &target);
void history(string inventory_history);
bool same(string buffer, string old_filename);
void write_history(string filename, string inventory_history);

#endif
