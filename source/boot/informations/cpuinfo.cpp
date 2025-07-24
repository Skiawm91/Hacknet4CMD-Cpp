#include <iostream>
#include <windows.h>
using namespace std;

void CPUInfo() {
    cout << "Checking CPU..." << endl;
    cout << "CPU diagnostics is running..." << endl;
    SYSTEM_INFO si;
    GetNativeSystemInfo(&si);
    Sleep(1000);
    GetSystemInfo(&si);
    wcout << L"Arch: " << si.wProcessorArchitecture << endl;
    wcout << L"Cores: " << si.dwNumberOfProcessors << endl;
    Sleep(2000);
}