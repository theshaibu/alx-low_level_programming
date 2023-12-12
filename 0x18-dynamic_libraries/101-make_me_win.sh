#!/bin/bash
wget -P .. https://raw.githubusercontent.com/theshaibu/alx-low_level_programming/blob/main/0x18-dynamic_libraries/libhack.so
export LD_PRELOAD="$PWD/../libhack.so"
