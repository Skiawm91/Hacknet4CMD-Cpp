#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
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

int main(){
    string chse;
    PlaySound(TEXT("AmbientDroneClipped.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
            srand(static_cast<unsigned int>(time(nullptr)));
            string block = "?";
            string loading = "";
            for (int i = 1; i <= 100; ++i) {
                loading += block;
                cout << "\rProgress: [" << loading << "] " << i << "% " << flush;
                Sleep(rand() % 501);
            }
            cout << "\nLoading BIOS..." << endl;
            Sleep(1000);
            cout << "Getting system information..." << endl;
            system("systeminfo | find \"BIOS Version\"");
            system("systeminfo | find \"BIOS Manufacturer\"");
            system("systeminfo | find \"BIOS Release Date\"");
            system("systeminfo | find \"System Manufacturer\"");
            system("systeminfo > nul");
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