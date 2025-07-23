#include <string>
#include <atomic>
#include <thread>
#pragma once
using namespace std;
extern thread musicThread; 
extern atomic<bool> loop;
void playSound(const string& soundFile, const int& time);