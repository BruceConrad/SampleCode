/*
//Bruce Conrad
//BST.h
//This is the header file for the HashTable class
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>

using namespace std;


typedef int HashTableItem;

class HashTable
{
    public:
        HashTable();
        
        void UnsortedInsert(HashTableItem hashTableValue);
        //Narrative: Adds a node to the Hash Table in any order in the
        //proper bucket
        //Pre-condition: none
        //Post-condition: hashTableValue has been inserted into
        //the proper bucket
        
        void SortedInsert(HashTableItem hashTableValue);
        //Narrative: Adds a node to the Hash Table in sorted order into
        //the proper bucket
        //Pre-condition: none
        //Post-condition: hashTableValue has been inserted into the
        //proper bucket
        
        bool Search(HashTableItem hashTableValue);
        //Narrative: Searches the Hash Table for a value (unsorted)
        //Pre-condition: none
        //Post-condition: either true is returned because the value is found,
        //or false is returned because the value is not in the Hash Table
        
        bool SortedSearch(HashTableItem hashTableValue);
        //Narrative: Searches the Hash Table for a value (sorted)
        //Pre-condition: none
        //Post-condition: either true is returned because the value is found,
        //or false is returned because the value is not in the Hash Table
        
        void PrintBucketsDawg();
        //Narrative: A debugging function to test if the inserts are properly
        //working or if they need to be debugged
        //Pre-condition: none
        //Post-condition: Buckets have been printed to screen
        
        int GetNumComparisons();
        //Narrative: Returns the total number of comparisons
        //Pre-condition: none
        //Post-condition: total number of comparisons is returned
        
    private:
        struct HashTableNode
        {
            HashTableNode* hashLink;
            HashTableItem hashData;
        };
        
        static const int listSize = 10;
        HashTableNode* hashArray[listSize];
        HashTableNode hashNode;
        int numComparisons = 0;
        
        int HashFunction(int uwu);
        //Narrative: Assigns a value to a bucket in the Hash Table
        //Pre-condition: none
        //Post-condition: value has been assigned to a bucket based
        //on this function
};

#endif
