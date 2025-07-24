#include "cmds.h"
#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <unistd.h>
#endif
#include <string>
#include <sstream>
using namespace std;

void WAIT(const string& content) {
    string arg1, arg2;
    istringstream args(content);
    args >> arg1 >> arg2;
    try {
        double seconds = stod(arg1);
        #ifdef _WIN32
        Sleep(static_cast<int>(seconds * 1000));
        #elif __APPLE__
        usleep(static_cast<int>(seconds * 1000000));
        #endif
    } catch (const invalid_argument) {}
}