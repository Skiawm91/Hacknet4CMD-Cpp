#include <iostream>
#include <string>
#include <windows.h>
#include "boot.h"
#include "informations/infos.h"
#include "utilities/utils.h"
#include "../logUI.h"
using namespace std;

void Boot() {
    srand(static_cast<unsigned int>(time(nullptr)));
    string block = "=";
    string loading = "";
    for (int i = 1; i <= 100; ++i) {
        loading += block;
        cout << "\rProgress: [" << loading << "] " << i << "% " << flush;
        Sleep(rand() % 501);
    }
    system("cls");
    cout << "Loading BIOS..." << endl;
    Sleep(1000);
    OSInfo();
    cout << "BIOS loaded successfully." << endl;
    Sleep(2000);
    CPUInfo();
    cout << "Loading operating system..." << endl;
    Sleep(3000);
    cout << "Operating system loaded successfully." << endl;
    Sleep(1000);
    cout << "Starting services..." << endl;
    cout << "Services initializing..." << endl;
    Network();
    Avast();
    Sleep(3000);
    cout << "Services started." << endl;
    Sleep(2000);
    cout << "\n\n";
    cout << "Booting complete." << endl;
    Sleep(3000);
    LogUI();
    return;
}