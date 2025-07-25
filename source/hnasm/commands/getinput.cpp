#include "cmds.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string input;

void GETINPUT(const string& content) {
    cout << content;
    getline(cin, input);
}