#!/bin/bash

rm -rf build
mkdir build
cd opegl-c
./embed-shaders.sh
