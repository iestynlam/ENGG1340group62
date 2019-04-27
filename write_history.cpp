#include <fstream>
#include <ctime>
#include "all_functions.h"
using namespace std;
const string filename = "inventory.txt";
const string inventory_history = "inventory_history.txt";

void write_history(string filename, string inventory_history) {
  ofstream write;
  write.open(inventory_history.c_str(), ios::app);
  ifstream input;
  input.open(filename.c_str());
  string line;
  time_t t = time(0);   // get time now
  tm* now = localtime(&t); // pointer to localtime
  write << endl << now->tm_mday << '-' << (now->tm_mon + 1) << '-' <<  (now->tm_year + 1900) << endl;
  while (getline(input, line)){
    write << line << endl;
  }
  write.close();
  input.close();
}
