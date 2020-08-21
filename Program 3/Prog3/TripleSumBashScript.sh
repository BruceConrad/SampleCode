#!/bin/bash


echo "***********Compiling TripleSum.cpp*********"
echo
c++ TripleSum.cpp -o TripleSum


echo "**************Beginning runs of TripleSum************"
echo
./TripleSum

echo "**************Would you like to run the program again?********"
echo

read answer

while [ $answer == "Yes" ]
do
    ./TripleSum
    
    echo "****************Would you like to run the program again?**********"
    echo
    
    read answer
done

echo "**********Ending BASH Script!***********"
