#include <iostream>
#include <string>
#include <windows.h>
#include "logUI.h"
using namespace std;

void LogUI() {
    SetConsoleTitleA("Hacknet Login");
    string name;
    string pwd;
    while(true) {
        system("cls");
        cout << "Please login a user. If have no any user, login \"guest\"" << endl;
        cout << "Login: ";
        cin >> name;
        if (name=="hoyiqiang") {
            cout << "Password: ";
            cin >> pwd;
            if (pwd=="hoyiqiang1006") {
                MessageBoxA(
                    NULL,
                    "Login success!\n    Welcome!",
                    "Hacknet LogUI",
                    MB_ICONINFORMATION | MB_OK
                );
                break;// Coming Soon!
            } else {
                MessageBoxA(
                    NULL,
                    "Password Invalid!\nPlease try again!",
                    "Hacknet LogUI",
                    MB_ICONERROR | MB_OK
                );
            }
        } else if (name=="guest") {
            break; // Coming Soon!
        }
    }

}