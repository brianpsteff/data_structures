#! /bin/bash

# Simple BASH script to generate a file of 10000 random numbers for testing #

if [ -a ./rand_keys.txt ]; then
	rm rand_keys.txt
fi

if [ -a ./rand_data.txt ]; then
	rm rand_data.txt
fi

for i in {1..10000}; do
	echo $RANDOM >> rand_keys.txt
done;

for j in {1..10000}; do
	echo $RANDOM >> rand_data.txt
done;
