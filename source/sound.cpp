#include <string>
#include <unistd.h>
#include "sound.h"
#include <atomic>
#include <thread>
using namespace std;

atomic<bool> loop(true);
std::thread musicThread;

void playSound(const string& soundFile, const int& time) {
    while(loop) {
        string soundcmd = "afplay ./assets/musics/" + soundFile + " &";
        system(soundcmd.c_str());
        usleep(time);
    }
}
