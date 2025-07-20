#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "boot.h"
using namespace std;

int main(){
    SetConsoleTitleA("Hacknet");
    string chse;
    PlaySound(TEXT("sounds/AmbientDroneClipped.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    while(true) {
        system("cls");
        cout << "\n\n\n\n\n"
             << "               ¢i¢iùß  ¢i¢iùß  ¢i¢i¢i¢i¢iùß   ¢i¢i¢i¢i¢iùß  ¢i¢iùß  ¢i¢iùß ¢i¢i¢iùß  ¢i¢iùß ¢i¢i¢i¢i¢i¢i¢iùß ¢i¢i¢i¢i¢i¢i¢i¢iùß\n"
             << "               ¢i¢iùø  ¢i¢iùø ¢i¢iùÝ¢¤¢¤¢i¢iùß ¢i¢iùÝ¢¤¢¤¢i¢iùß ¢i¢iùø ¢i¢iùÝùå ¢i¢i¢i¢iùß ¢i¢iùø ¢i¢iùÝ¢¤¢¤¢¤¢¤ùå ùã¢¤¢¤¢i¢iùÝ¢¤¢¤ùå\n"
             << "               ¢i¢i¢i¢i¢i¢i¢iùø ¢i¢i¢i¢i¢i¢i¢iùø ¢i¢iùø  ùã¢¤ùå ¢i¢i¢i¢i¢i¢¤ùå  ¢i¢iùÝ¢i¢iùß¢i¢iùø ¢i¢i¢i¢i¢iùß      ¢i¢iùø   \n"
             << "               ¢i¢iùÝ¢¤¢¤¢i¢iùø ¢i¢iùÝ¢¤¢¤¢i¢iùø ¢i¢iùø  ¢i¢iùß ¢i¢iùÝ¢¤¢i¢iùß  ¢i¢iùøùã¢i¢i¢i¢iùø ¢i¢iùÝ¢¤¢¤ùå      ¢i¢iùø   \n"
             << "               ¢i¢iùø  ¢i¢iùø ¢i¢iùø  ¢i¢iùø ùã¢i¢i¢i¢i¢iùÝùå ¢i¢iùø ùã¢i¢iùß ¢i¢iùø ùã¢i¢i¢iùø ¢i¢i¢i¢i¢i¢i¢iùß    ¢i¢iùø   \n"
             << "               ùã¢¤ùå  ùã¢¤ùå ùã¢¤ùå  ùã¢¤ùå  ùã¢¤¢¤¢¤¢¤ùå  ùã¢¤ùå  ùã¢¤ùå ùã¢¤ùå  ùã¢¤¢¤ùå ùã¢¤¢¤¢¤¢¤¢¤¢¤ùå    ùã¢¤ùå   \n"
             << "                [C++ Edition by Skiawm91]\n"
             << "\n\n\n\n\n\n\n"
             << "                             1) ¥D­¶­±\n"
             << "                             2) Â÷¶}Hacknet\n"
             << "\n\n\n\n\n\n\n\n\n";
            cout << "choose: ";
        cin >> chse;
        if (chse=="1") {
            Boot();
        } else if (chse=="2") {
            string yn;
            system("cls");
            while(true) {
                cout << "½T©w­nÂ÷¶}Hacknet¶Ü? (y/n)\n";
                cout << "choose: ";
                cin >> yn;
                if (yn=="y") {
                    return 0;
                } else if (yn=="n") {
                    break;
                }
            }
        }
    }
    return 0;
}