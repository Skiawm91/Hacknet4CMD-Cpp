#include "audio.h"
#include "logUI.h"
#include "hnasm/hnasm.h"
#ifdef _WIN32
#include <windows.h>
#undef PlaySound
#elif __APPLE__
#include <unistd.h>
#include <libgen.h>
#include <mach-o/dyld.h>
#endif
#include <iostream>
#include <cstdlib>
#include <string>
#include "porthack.h"
using namespace std;

int main(){
    #ifdef _WIN32
    SetConsoleTitleA("Hacknet");
    #elif __APPLE__
    char path[PATH_MAX];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0) {
        char path_copy[PATH_MAX];
        strncpy(path_copy, path, PATH_MAX);
        path_copy[PATH_MAX - 1] = '\0';
        char* dir = dirname(path_copy);
        chdir(dir);
    }
    cout << "\033]0;$title\007";
    #endif
    int chse;
    StopAudio();
    PlayAudio("AmbientDroneClipped.wav");
    while(true) {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
        int chse;
        HNASM("ui.chns", "HOME");
        switch(chse) {
            case 1:
                LogUI();
            case 4:
                string yn;
                #ifdef _WIN32
                system("cls");
                #elif __APPLE__
                system("clear");
                #endif
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