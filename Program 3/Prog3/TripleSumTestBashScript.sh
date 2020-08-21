#!/bin/bash


echo "***********Compiling TripleSumTestDriver.cpp*********"
echo
c++ TripleSumTestDriver.cpp -o TripleSumTestDriver


echo "**************Beginning runs of TripleSumTestDriver************"
echo
./TripleSumTestDriver

echo "**************Would you like to run the program again?********"
echo

read answer

while [ $answer == "Yes" ]
do
    ./TripleSumTestDriver
    
    echo "****************Would you like to run the program again?**********"
    echo
    
    read answer
done

echo "**********Ending BASH Script!***********"
