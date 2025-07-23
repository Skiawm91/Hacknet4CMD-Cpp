#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include "hnasm.h"
using namespace std;

void HNASM(const string& filename) {
    string scriptPath = "assets/scripts/" + filename;
    ifstream file(scriptPath);
    string line;
    string command, content;
    while(getline(file, line)) {
        command.clear();
        content.clear();
        istringstream got(line);
        got >> command;
        getline(got, content);
        if (command=="WAIT") {
            string arg1, arg2;
            istringstream args(content);
            args >> arg1 >> arg2;
            try {
                double seconds = stod(arg1);
                usleep(static_cast<int>(seconds * 1000000));
            } catch (const invalid_argument) {}
        }
        if (command=="PRINT") {
            if (content.empty()) {
                cout << endl;
            } else {
                cout << content << endl;
            }
        }
    }
}