#!/bin/bash

cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -GNinja
ninja
cp -r ../opegl-c/shaders .
./$1
