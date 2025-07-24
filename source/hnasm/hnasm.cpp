#include "hnasm.h"
#include "commands/cmds.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <unistd.h>
#endif
using namespace std;

void HNASM(const string& fileName, const string& partName = "") {
    string scriptPath = "assets/scripts/" + fileName;
    ifstream file(scriptPath);
    string line;
    string command, content;
    bool readcmd;
    if (partName.empty()) {readcmd=true;}
    while(getline(file, line)) {
        command.clear();
        content.clear();
        if (line==("BEGIN_" + partName)) {readcmd=true;}
        if (!partName.empty() && line==("END_" + partName)) {break;}
        istringstream got(line);
        got >> command;
        getline(got, content);
        if (readcmd) {
            if (command=="WAIT") {WAIT(content);}
            else if (command=="CLEAR") {CLEAR();}
            else if (command=="PRINT") {PRINT(content);}
            else if (command=="PLAYSOUND") {PLAYSOUND(content);}
            // else if (command=="COMINGSOON") {}
        }
    }
}