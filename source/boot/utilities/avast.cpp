#include "utils.h"
#include <iostream>
#include <windows.h>
using namespace std;

void Avast() {
    cout << "Starting Avast 1.0..." << endl;
    cout << "[Avast] Running antivirus scan..." << endl;
    Sleep(1000);
    cout << "[Avast] Scanning for viruses..." << endl;
    Sleep(6000);
    cout << "[Avast] No viruses found." << endl;
    Sleep(1000);
}