#!/bin/bash

# * Compile file (try replacing -fno-pie with -no-pie if the addresses are wrong on your local machine)
gcc -w --std=c99 -g -m32 -no-pie -fno-stack-protector -mpreferred-stack-boundary=2 hw3.c -o hw3

# * Run file under no-ASLR wrapper
setarch `uname -m` -R ./hw3




