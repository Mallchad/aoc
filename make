#!/bin/bash

clang++ main.cpp -o advent-of-code \
        -std=c++20 \
        -O1 \
        -D DEBUG \
        # -Weverything \

        if [ $1 == run ]
then
    ./advent-of-code
fi
