#include "noobornonoob.h"
#include "cmd.h"
#include "tutorial.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Noobornonoob() {
    string sel;
    while(true) {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
        cout << "Welcome to Hacknet CMD!" << endl;
        cout << "If you never played this, type \"y\", else type \"n\"" << endl;
        cout << "type: ";
        cin >> sel;
        if (sel=="n") {
            Cmd();
            return;
        } else if (sel=="y") {
            Tutorial();
            return;
        }
    }
}