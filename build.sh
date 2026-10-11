#! /bin/bash

git clone  https://github.com/raylib-extras/raylib-quickstart.git raysrc &&
cd raysrc/build &&
./premake5 gmake &&
cd .. &&
make &&
cd .. &&
rm raysrc/src/main.c &&
cp main.c raysrc/src &&
cp src/* raysrc/resources
