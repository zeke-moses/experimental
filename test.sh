#!/bin/bash

# Simple bash script to test my C program(s)

#make && ./exp && make clean

make

#sudo python get-location.py > ./exp
#OUTPUT="$(sudo python get-location.py)"

#./exp "${OUTPUT}"
# warning: feeds as one arg, not 2

./exp 29.426593 -98.489824

make clean
