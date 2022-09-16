#!/bin/bash
betty *.c *.h
export COMPILE=1
if [ "$COMPILE" = 1 ]
then
    gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o factors && valgrind ./factors tests/rsa-1
fi
