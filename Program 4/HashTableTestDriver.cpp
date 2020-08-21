/*
//Bruce Conrad
//This is the Test Driver for the HashTable class.
*/

#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;


void TestSortedInsert(int ary[], int arySize, HashTable& tester1);

void TestUnsortedInsert(int ary[], int arySize, HashTable& tester2);

void TestSearch (HashTable& tester1);

int main()
{
    int testerArray[10] = {1,5,9,66,42,88,3,57,52,4};
    
    HashTable tester1;
    HashTable tester2;
    
    
    cout << "Before Sorted Insert!" << endl;
    TestSortedInsert(testerArray, 10, tester1);
    cout << "After Sorted Insert!" << endl;
    
    cout << "Before Unsorted Insert!" << endl;
    TestUnsortedInsert(testerArray, 10, tester2);
    cout << "After Unsorted Insert!" << endl;
    
    tester1.PrintBucketsDawg();
    tester2.PrintBucketsDawg();
    
    cout << "Before Search!" << endl;
    TestSearch(tester2);
    cout << "After Search!" << endl;
    
    
    return 0;
    
    
}

void TestSortedInsert(int ary[], int arySize, HashTable& tester1)
{
    for(int i = 0; i < arySize; i++)
    {
        tester1.SortedInsert(ary[i]);
        cout << "Inserted: " << ary[i] << endl;
        cout << ary[i]%arySize << endl;
    }
}

void TestUnsortedInsert(int ary[], int arySize, HashTable& tester2)
{
    for(int i = 0; i < arySize; i++)
    {
        tester2.UnsortedInsert(ary[i]);
    }
}

void TestSearch(HashTable& tester1)
{
    tester1.UnsortedInsert(62);
    tester1.PrintBucketsDawg();
    tester1.Search(42);
}
