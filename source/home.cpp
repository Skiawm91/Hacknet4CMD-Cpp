#include <unistd.h>
#include <iostream>
#include <libgen.h>
#include <limits.h>
#include <mach-o/dyld.h>
#include <cstdlib>
#include <string>
#include <thread>
#include "sound.h"
#include "boot.h"
using namespace std;

int main(int argc, char* argv[]){
    char path[PATH_MAX];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0) {
        char path_copy[PATH_MAX];
        strncpy(path_copy, path, PATH_MAX);
        path_copy[PATH_MAX - 1] = '\0';
        char* dir = dirname(path_copy);
        chdir(dir);
    }
    cout << "\033]0;Hacknet\a";
    string chse;
    system("killall afplay");
    loop=true;
    musicThread = thread(playSound, "AmbientDroneClipped.wav", 108125057);
    while(true) {
        system("clear");
        cout << "\n\n\n\n\n"
             << "               ██╗  ██╗  █████╗   █████╗  ██╗  ██╗ ███╗  ██╗ ███████╗ ████████╗\n"
             << "               ██║  ██║ ██╔══██╗ ██╔══██╗ ██║ ██╔╝ ████╗ ██║ ██╔════╝ ╚══██╔══╝\n"
             << "               ███████║ ███████║ ██║  ╚═╝ █████═╝  ██╔██╗██║ █████╗      ██║   \n"
             << "               ██╔══██║ ██╔══██║ ██║  ██╗ ██╔═██╗  ██║╚████║ ██╔══╝      ██║   \n"
             << "               ██║  ██║ ██║  ██║ ╚█████╔╝ ██║ ╚██╗ ██║ ╚███║ ███████╗    ██║   \n"
             << "               ╚═╝  ╚═╝ ╚═╝  ╚═╝  ╚════╝  ╚═╝  ╚═╝ ╚═╝  ╚══╝ ╚══════╝    ╚═╝   \n"
             << "                [C++ Edition by Skiawm91]\n"
             << "\n\n\n\n\n\n\n"
             << "                             1) Play\n"
             << "                             2) Quit Hacknet\n"
             << "\n\n\n\n\n\n\n\n\n";
            cout << "choose: ";
        cin >> chse;
        if (chse=="1") {
            Boot();
        } else if (chse=="2") {
            string yn;
            system("clear");
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