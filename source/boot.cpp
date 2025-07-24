#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <sys/sysctl.h>
#include "boot.h"
#include "logUI.h"
using namespace std;

// Get Information by GPT
string getSysctlString(const char* name) {
    size_t size = 0;
    sysctlbyname(name, nullptr, &size, nullptr, 0);
    char* value = new char[size];
    sysctlbyname(name, value, &size, nullptr, 0);
    string result(value);
    delete[] value;
    return result;
}

int getSysctlInt(const char* name) {
    int value = 0;
    size_t size = sizeof(value);
    sysctlbyname(name, &value, &size, nullptr, 0);
    return value;
}

void Boot() {
    srand(static_cast<unsigned int>(time(nullptr)));
    string block = "=";
    string loading = "";
    for (int i = 1; i <= 100; ++i) {
        loading += block;
        cout << "\rProgress: [" << loading << "] " << i << "% " << flush;
        usleep(rand() % 501000);
    }
    system("clear");
    cout << "Loading BIOS..." << endl;
    usleep(1000000);
    cout << "Getting system information..." << endl;
    for (int i = 1; i <= 5; ++i) {
         // system("systeminfo > nul"); // Skipped for macOS
    }
    cout << "OS Name: Mac OS X" << endl;
    cout << "OS Version: " << getSysctlString("kern.osproductversion") << endl;
    cout << "OS Arch: " << getSysctlString("hw.machine") << endl;
    cout << "BIOS loaded successfully." << endl;
    usleep(2000000);
    cout << "Checking CPU..." << endl;
    cout << "CPU diagnostics is running..." << endl;
    usleep(1000000);
    cout << "Cores: " << getSysctlInt("hw.ncpu") << endl;
    usleep(2000000);
    cout << "Loading operating system..." << endl;
    usleep(3000000);
    cout << "Operating system loaded successfully." << endl;
    usleep(1000000);
    cout << "Starting services..." << endl;
    cout << "Services initializing..." << endl;
    usleep(3000000);
    cout << "Services started." << endl;
    usleep(2000000);
    cout << "Configuring network..." << endl;
    system("ipconfig");
    cout << "Starting Avast 1.0..." << endl;
    cout << "[Avast] Running antivirus scan..." << endl;
    usleep(1000000);
    cout << "[Avast] Scanning for viruses..." << endl;
    usleep(6000000);
    cout << "[Avast] No viruses found." << endl;
    usleep(1000000);
    cout << "\n\n";
    cout << "Booting complete." << endl;
    usleep(3000000);
    LogUI();
    return;
}