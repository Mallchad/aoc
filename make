#!/bin/bash

clang++ main.cpp -o advent-of-code
if [ $1 == run ]
then
    ./advent-of-code
fi
