//makes every letter in the user input lowercase, used for error handling and variances in user input

#include <string>
#include "all_functions.h"
using namespace std;

string lowercase(string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}
