#!/bin/bash

make

clear

printf "Enter your Alphabet : "

read input

echo "Starting..."

insmod kbleds.ko c=$input

sleep  8

echo "...Finished"

rmmod kbleds.ko

clear

printf "Enter another? [y/n] :"

read choice

if [ $choice == "y" -o $choice == "Y" ]
then

	bash run.sh

fi
