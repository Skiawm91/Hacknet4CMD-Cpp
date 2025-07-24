#include "cmds.h"

void CLEAR() {
    #ifdef _WIN32
    system("cls");
    #elif __APPLE__
    system("clear");
    #endif
}