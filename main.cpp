#include <iostream>
#include <string>
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
    string input;
    while (input != "exit"){
        cout << "Please input your option: \nType \"options\" to view what are the options.";
        switch (input){
            case (options){
                options();
            }
        }
    }
}
// to view to options and connect to 
void options(){
    cout << "Search"
}

void help(){

}
