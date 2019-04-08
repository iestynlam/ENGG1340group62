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
void options();
void help(string option);
void intro();

int main(){
    string option;
    intro();
    while (getline(cin, option)){
        // change() <- which include both point 5 and 6, where update the commodity information every time before
        if (option == "options"){
            cout << endl;
            options();
            intro();
        }
        else{
            if (option == "help"){
            cout << "Which option do you to know more?" << endl;
            cin >> option;
            help(option);
            intro();
            }
        else{
            if (option == "exit"){
                cout << "This is the end of the program." << endl;
                break;
            }
        // More options insect here
        else{
            cout << "Undefined option, please enter the option again." << endl << endl;
            intro();
            }
        }
    }
}

}
// to view the options (two lines view all options)
void options(){
    cout << "search" << ' ' << "insect" << ' ' << "delete" << ' ' << "exit" << endl
    << "options" << ' ' << "help" << ' ' << "exit" << endl << endl;
    // may use a line to replace endl ???
}

// view options explaination
void help(string option){

    if (option == "options"){
        cout << "To view all options." << endl;
    }
    else{if (option == "help"){
        cout << "To view options explaination and guideline." << endl;
    }
    else{if (option == " search"){
        cout << "To search commodities according to different filters (e.g. in-stock/out-of-stock)." << endl;
    }
    else{if (option == "insect"){
        cout << "To insert new commodity with basic information (name, manufacturer, amount, price, availability of shop(s)) after each procurement." << endl;
    }
    else{if (option == "delete"){
        cout << "To delete obsolete commodities." << endl;
    }
    else{if (option == "exit"){
        cout << "To exit the program." << endl;
    }
    else{
        cout << "This is not an option." << endl;
    }
}
}
}
}
}
}

void intro(){
    cout << "Please input your option: \nType \"options\" to view what are the options and \"help\" to see further explaination of the options."
    << "\nType \"exit\" if you want to quit the program.\n";
}
