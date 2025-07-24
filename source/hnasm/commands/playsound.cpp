#include "cmds.h"
#include "../../sound.h"
#include <string>
#ifdef _WIN32
#include <windows.h>
#undef PlaySound
#endif
#include <sstream>
using namespace std;

void PLAYSOUND(const string& content) {
    string arg1;
    istringstream args(content);
    args >> arg1;
    PlaySound(arg1);
}