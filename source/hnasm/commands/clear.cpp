#include "cmds.h"

void CLEAR() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}