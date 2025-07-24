#include "infos.h"
#include <windows.h>
#include <cstdlib>
#include <string>
#include <iostream>
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

void OSInfo() {
    cout << "Getting system information..." << endl;
    for (int i = 1; i <= 5; ++i) {
        system("systeminfo > nul");
    }
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
}