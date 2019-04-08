#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
Features of the Program
1. Search commodities according to different filters (e.g. in-stock/out-of-stock)
2. Insert new commodity with basic information (name, manufacturer, amount, price, availability of shop(s)) after each procurement
3. Delete obsolete commodities
4. Update commodity information
5. Automatic change of inventory status according to the amount of commodity that is currently available (e.g. when the amount reaches zero, the inventory status would become "out-of-stock")
6. Deliver alerts when the commodity is "out-of-stock"
*/

int main(){
    string input, option;
    istringstream inputline(input);
    while (inputline >> option){
        cout << "Please input your option: \nType \"options\" to view what are the options.\nType \"exit\" if you want to quit the program";
        switch (option){
            case ("options"){
                options();
            }
            case ("help"){

            }
            case ("exit"){
                cout << "This is the end of the program." << endl;
                return 0;
            }
        }
    }
}
// to view the options
void options(){
    cout << "Search" <<
}

//
void help(string){
    cout << "Which option do you to know more?" << endl;
    
}
