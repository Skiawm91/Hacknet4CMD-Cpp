#include <iostream>
#include <string>
#include "noobornonoob.h"
#include "cmd.h"
#include "tutorial.h"
using namespace std;

void Noobornonoob() {
    string sel;
    while(true) {
        system("cls");
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