#!/bin/bash
echo Starting Build...
cd "$(dirname "$0")"
rm -rf build
mkdir build
cp -r assets build/
clang++ source/*.cpp -framework AudioToolbox -framework CoreFoundation -std=c++20 -o build/Hacknet
echo "Done."
read -p "Press Enter to Run Application."
./build/Hacknet