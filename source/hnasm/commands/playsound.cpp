#include "cmds.h"
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <sstream>
using namespace std;

void PLAYSOUND(const string& content) {
    string arg1;
    istringstream args(content);
    args >> arg1;
    #ifdef _WIN32
    PlaySoundA(arg1.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    #endif
}