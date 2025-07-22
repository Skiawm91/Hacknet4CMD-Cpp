#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include "boot.h"
#include "logUI.h"
using namespace std;

// Pre get "OS Name"/"OS Verion" by ChatGPT
wstring getRegValue(const wchar_t* keyName) {
    HKEY hKey;
    wchar_t buf[256] = {0};
    DWORD size = sizeof(buf);
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE,
                      L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
                      0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        return 0;
    }
    if (RegQueryValueExW(hKey, keyName, nullptr, nullptr, (LPBYTE)buf, &size) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return 0;
    }
    RegCloseKey(hKey);
    return buf;
}
DWORD GetRegDWORDValue(const wchar_t* name) {
    HKEY hKey;
    DWORD data = 0;
    DWORD size = sizeof(data);
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE,
                      L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
                      0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return 0;
    if (RegQueryValueExW(hKey, name, nullptr, nullptr, (LPBYTE)&data, &size) != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return 0;
    }
    RegCloseKey(hKey);
    return data;
}

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
    cout << "\nLoading BIOS..." << endl;
    Sleep(1000);
    cout << "Getting system information..." << endl;
    for (int i = 1; i <= 5; ++i) {
        system("systeminfo > nul");
    }
    SYSTEM_INFO si;
    GetNativeSystemInfo(&si);
    if (_wtoi(getRegValue(L"CurrentBuildNumber").c_str()) >= 22000) {
        wcout << L"OS Name: Windows 11" << endl;
    } else if (_wtoi(getRegValue(L"CurrentBuildNumber").c_str()) >= 10240 && _wtoi(getRegValue(L"CurrentBuildNumber").c_str()) < 22000) {
        wcout << L"OS Name: Windows 10" << endl;
    } else if (_wtoi(getRegValue(L"CurrentBuildNumber").c_str()) >= 9600 && _wtoi(getRegValue(L"CurrentBuildNumber").c_str()) < 10240) {
        wcout << L"OS Name: Windows 8.1" << endl;
    } else {
        OSVERSIONINFOEXW osvi = { sizeof(osvi) };
        GetVersionExW((OSVERSIONINFOW*)&osvi);
        wcout << L"OS Version: " << osvi.dwMajorVersion << L"." << osvi.dwMinorVersion << endl;
    }
    wcout << L"OS Version: " << GetRegDWORDValue(L"CurrentMajorVersionNumber") << "." << GetRegDWORDValue(L"CurrentMinorVersionNumber") << endl;
    wcout << L"OS Arch: " 
          << (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ? L"amd64" : L"ia32") 
          << L"\n";
    cout << "BIOS loaded successfully." << endl;
    Sleep(2000);
    cout << "Checking CPU..." << endl;
    cout << "CPU diagnostics is running..." << endl;
    Sleep(1000);
    GetSystemInfo(&si);
    wcout << L"Cores: " << si.dwNumberOfProcessors << L"\n";
    Sleep(2000);
    cout << "Loading operating system..." << endl;
    Sleep(3000);
    cout << "Operating system loaded successfully." << endl;
    Sleep(1000);
    cout << "Starting services..." << endl;
    cout << "Services initializing..." << endl;
    Sleep(3000);
    cout << "Services started." << endl;
    Sleep(2000);
    cout << "Configuring network..." << endl;
    system("ipconfig /all");
    cout << "Starting Avast 1.0..." << endl;
    cout << "[Avast] Running antivirus scan..." << endl;
    Sleep(1000);
    cout << "[Avast] Scanning for viruses..." << endl;
    Sleep(6000);
    cout << "[Avast] No viruses found." << endl;
    Sleep(1000);
    cout << "\n\n";
    cout << "Booting complete." << endl;
    Sleep(3000);
    LogUI();
}