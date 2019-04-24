//fills empty spaces in a string with '_' characters. used for error handling in search processing as well as
//ensuring names in the system have no spaces so that items can be easily retrieved from the 'inventory.txt'

void fill_spaces(string &str) {
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == " ") {
      str.replace(i,1,"_");
    }
  }
}
