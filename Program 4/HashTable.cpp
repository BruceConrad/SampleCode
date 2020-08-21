/*
//Bruce Conrad
//BST.h
//This is the implementation file for the HashTable class
*/

#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    for(int i = 0; i < listSize; i++)
    {
        hashArray[i] = NULL;
    }
}

void HashTable::UnsortedInsert(HashTableItem hashTableValue)
{
    int assignmentValue;
    HashTableNode* tempNode = new HashTableNode;
    
    assignmentValue = HashFunction(hashTableValue);
    tempNode->hashData = hashTableValue;
    
    if(hashArray[assignmentValue] == NULL)
    {
        hashArray[assignmentValue] = tempNode;
    }
    
    else
    {
        tempNode->hashLink = hashArray[assignmentValue];
        hashArray[assignmentValue] = tempNode;
    }
    
    tempNode = NULL;
    delete tempNode;
}

void HashTable::SortedInsert(HashTableItem hashTableValue)
{
    int assignmentValue;
    HashTableNode* prevNode = NULL;
    HashTableNode* nextNode = NULL;
    bool inList = false;
    
    HashTableNode* item = new HashTableNode;
    item->hashData = hashTableValue;
    
    assignmentValue = HashFunction(hashTableValue);
    nextNode = hashArray[assignmentValue];
    
    if(hashArray[assignmentValue] == NULL)
    {
       hashArray[assignmentValue] = item;
    }
    
    else
    {
        prevNode = nextNode;
        nextNode = nextNode->hashLink;
            
        while(nextNode != NULL && !inList && nextNode->hashData < item->hashData)
        {
            prevNode = nextNode;
            nextNode = nextNode->hashLink;
        }
            
        item->hashLink = nextNode;
            
        if(prevNode == NULL)
        {
            hashArray[assignmentValue] = item;
        }
        else
        {
            prevNode->hashLink = item;
        }
    }
    
    item = NULL;
    delete item;
    
}

bool HashTable::Search(HashTableItem hashTableValue)
{
    bool found = false;
    HashTableNode* tempNode = new HashTableNode;
    int comparisons = 0;
    int assignmentValue = HashFunction(hashTableValue);
    
    tempNode = hashArray[assignmentValue];
    
    while(!found && tempNode != NULL)
    {
        comparisons++;
        if(tempNode->hashData == hashTableValue)
        {
            found = true;
        }
            
        tempNode = tempNode->hashLink;
    }
    numComparisons += comparisons;
    
    return(found);
}

bool HashTable::SortedSearch(HashTableItem hashTableValue)
{
    bool found = false;
    HashTableNode* tempNode = new HashTableNode;
    int comparisons = 0;
    int assignmentValue = HashFunction(hashTableValue);
    
    tempNode = hashArray[assignmentValue];
    
    while(!found && tempNode != NULL && hashTableValue >= tempNode->hashData)
    {
        comparisons++;
        if(tempNode->hashData == hashTableValue)
        {
            found = true;
        }
            
        tempNode = tempNode->hashLink;
    }
    numComparisons += comparisons;
    
    return(found);
}

int HashTable::HashFunction(int uwu)
{
    return(uwu % listSize);
}

void HashTable::PrintBucketsDawg()
{
    HashTableNode* tempNode = NULL;
    
    for(int i = 0; i < listSize; i++)
    {
        cout << "Bucket: " << i << endl << endl;
        tempNode = hashArray[i];
        
        while(tempNode != NULL)
        {
            cout << tempNode->hashData << endl;
            tempNode = tempNode->hashLink;
        }
        cout << endl;
    }
}

 int HashTable::GetNumComparisons()
 {
     return(numComparisons);
 }
