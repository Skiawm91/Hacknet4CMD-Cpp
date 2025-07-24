#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "boot/boot.h"
#include "hnasm/hnasm.h"
#include "porthack.h"
using namespace std;

int main(){
    while(true) {
        string fileName, beginPart;
        cin >> fileName;
        cin >> beginPart;
        HNASM(fileName, beginPart);
    }
    SetConsoleTitleA("Hacknet");
    int chse;
    PlaySound(TEXT("assets/musics/AmbientDroneClipped.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
             << "                             1) Play\n"
             << "                             2) Settings\n"
             << "                             3) Quit Hacknet\n"
             << "\n\n\n\n\n\n\n\n";
            cout << "choose: ";
        cin >> chse;
        switch(chse) {
            case 1:
                Boot();
            case 3:
                string yn;
                system("cls");
                while(true) {
                    cout << "Are you sure to quit Hacknet? (y/n)\n";
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