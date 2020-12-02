#!/bin/bash

clang++ main.cpp -o advent-of-code \
        -Weverything \
        -std=c++20
if [ $1 == run ]
then
    ./advent-of-code
fi
