#ifndef ALL_FUNCTIONS_H
#define ALL_FUNCTIONS_H

struct commodity {
  string name; // name of commodity
  string manuf; // name of manufacturer
  int qty; // quantity of commodity
  commodity* next; // setting up linked list
} ;

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

void initialize_list(commodity* &head, string filename);
commodity* s_find_by_name(commodity* &head, string target);
commodity* find_by_name(commodity* &head);
void search_item(commodity* &head);
void edit_item(commodity* &target);
void display(commodity* &head);
void insert(commodity* &head);
void before_end_program(commodity* head);

#endif
