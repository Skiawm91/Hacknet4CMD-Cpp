#include "cmds.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void GETINPUT(const string& content) {
    string input;
    cout << content;
    getline(cin, input);
}