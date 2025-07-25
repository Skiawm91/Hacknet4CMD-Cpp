#include "cmds.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <string>
#include <sstream>
using namespace std;

#ifndef _WIN32
inline void Sleep(const int& ms) {usleep(ms * 1000);}
#endif

void WAIT(const string& content) {
    string arg1, arg2;
    istringstream args(content);
    args >> arg1, arg2;
    try {
        double seconds = stod(arg1);
        Sleep(static_cast<int>(seconds * 1000));
    } catch (const invalid_argument) {}
}