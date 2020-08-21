/*
//Bruce Conrad
//This is the Client for the BST and Hash Table Program.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include "HashTable.h"

using namespace std;

void DoBSTOperations(int ary[], int listSize);
//Narrative: Does the necessary BST ops per program specs
//Pre-condition: ary[] is populated with values and listSize > 0
//Post-condition: BST ops have been performed and num comparisons have been noted

void DoHashTableUnsortedOps(int ary[], int listSize);
//Narrative: Does the necessary Hash Table ops (unsorted) per program specs
//Pre-condition: ary[] is populated with values and listSize > 0
//Post-condition: Hash Table ops have been performed and num comparisons have been noted

void DoHashTableSortedOps(int ary[], int listSize);
//Narrative: Does the necessary Hash Table ops (sorted) per program specs
//Pre-condition: ary[] is populated with values and listSize > 0
//Post-condition: Hash Table ops have been performed and num comparisons have been noted

int main()
{
    ifstream inputFile;
    string fileName = "randomInts.txt";
    int listSize;
    int* ary;
    string numFromFileString;
    int numFromFileInt;
    
    cout << "Enter list size: ";
    cin >> listSize;
    
    ary = new int[listSize];
    
    inputFile.open(fileName.c_str());
    
    for(int i = 0; i < listSize; i++)
    {
        getline(inputFile, numFromFileString);
        numFromFileInt = stoi(numFromFileString, nullptr);
        ary[i] = numFromFileInt;
    }
    
    DoBSTOperations(ary, listSize);
    DoHashTableUnsortedOps(ary, listSize);
    DoHashTableSortedOps(ary, listSize);
    
    inputFile.close();
    
    return 0;
}

void DoBSTOperations(int ary[], int listSize)
{
    BST tree;
    
    cout << "Inserting the items!" << endl;
    
    for(int i = 0; i < listSize; i++)
    {
        tree.Insert(ary[i]);
    }
    
    cout << "Searching for the values!" << endl;
    
    for(int i = 0; i < listSize; i++)
    {
        tree.Search(ary[i]);
    }
    
    cout << "Total BST Comparisons: " << tree.GetNumComparisons() << endl;
}

void DoHashTableUnsortedOps(int ary[], int listSize)
{
    HashTable unsortedTable;
    
    cout << "Inserting the items!" << endl;
    
    for(int i = 0; i < listSize; i++)
    {
        unsortedTable.UnsortedInsert(ary[i]);
    }
    
    cout << "Searching for the values!" << endl;
    
    for(int i = 0; i < listSize; i++)
    {
        unsortedTable.Search(ary[i]);
    }
    
    cout << "Total Unsorted Hash Table Comparisons: ";
    cout << unsortedTable.GetNumComparisons() << endl;
}

void DoHashTableSortedOps(int ary[], int listSize)
{
    HashTable sortedTable;
    
    cout << "Inserting the items!" << endl;
    
    for(int i = 0; i < listSize; i++)
    {
        sortedTable.SortedInsert(ary[i]);
    }
    
    cout << "Searching for the values!" << endl;
    
    for(int i = 0; i < listSize; i++)
    {
        sortedTable.SortedSearch(ary[i]);
    }
    
    cout << "Total Sorted Hash Table Comparisons: ";
    cout << sortedTable.GetNumComparisons() << endl;
}
