// return True if the two files are the same
#include <fstream>
using namespace std;

bool same(string buffer, string old_filename){
  ifstream update;
  update.open(buffer.c_str());
  ifstream old;
  old.open(old_filename.c_str());
  string l1,l2;
  while (getline(update,l1) || (getline(old,l2))){
    getline(old,l2);
    if (l1 != l2){
      update.close();
      old.close();
      return false;
    }
  }
  update.close();
  old.close();
  return true;
}
