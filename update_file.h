// To update the inventory.txt when called
using namespace std;

void update_file(commodity* &head, string filename) {
  ofstream ostream;
  string line;
  commodity* &current = head;
  ostream.open(filename);
  while (current -> next != NULL){
    ostream << current -> name << ' ' << current -> manuf << ' ' << current -> qty << endl;
    current = current -> next;
  }
  ostream << current -> name << ' ' << current -> manuf << ' ' << current -> qty;
  ostream.close();
}
