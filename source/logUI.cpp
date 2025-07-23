#include <iostream>
#include <string>
#include <unistd.h>
#include "logUI.h"
#include "noobornonoob.h"
#include "cmd.h"
using namespace std;

void LogUI() {
    string name;
    string pwd;
    while(true) {
        system("clear");
        cout << "Please login a user. If have no any user, login \"guest\"" << endl;
        cout << "Login: ";
        cin >> name;
        if (name=="hoyiqiang") {
            cout << "Password: ";
            cin >> pwd;
            if (pwd=="hoyiqiang1006") {
                Cmd();
                return;
            }
        } else if (name=="guest") {
            Noobornonoob();
            return;
        }
    }
}