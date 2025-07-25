#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <fstream>
#include "logUI.h"
#include "noobornonoob.h"
#include "cmd.h"
using namespace std;

void LogUI() {
    string name;
    string pwd;
    while(true) {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
        cout << "Please login a user. If have no any user, login \"guest\"" << endl;
        cout << "Login: ";
        cin >> name;
        if (name=="hoyiqiang") {
            cout << "Password: ";
            cin >> pwd;
            if (pwd=="hoyiqiang1006") {
                #ifdef _WIN32
                MessageBoxA(
                    NULL,
                    "Login success!\n    Welcome!",
                    "Hacknet LogUI",
                    MB_ICONINFORMATION | MB_OK
                );
                #endif
                Cmd();
                return;
            } else {
                #ifdef _WIN32
                MessageBoxA(
                    NULL,
                    "Password Invalid!\nPlease try again!",
                    "Hacknet LogUI",
                    MB_ICONERROR | MB_OK
                );
                #endif
            }
        } else if (name=="guest") {
            Noobornonoob();
            return;
        }
    }
}