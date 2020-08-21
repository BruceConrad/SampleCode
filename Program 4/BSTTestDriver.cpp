/*
//Bruce Conrad
//The Test Client for the BST class.
*/

#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

void TestInsert(int testValues[], int testListSize, BST& rootNode);

void TestSearch(int searchValue, BST& tester);

void TestFindSuccessor(BST& tester, int successItem);

void TestFindPredecessor(BST& tester, int predItem);

void TestInorderTraverse(BST& tester);

void TestDelete(int deletionValue, BST& tester);

int main()
{
    int testArray[10] = {10, 8, 6, 3, 42, 56, 78, 1, 99, 666};
    BST testNode;
    
    cout << "Testing Insert!" << endl << endl;
    TestInsert(testArray, 10, testNode);
    cout << "Done!" << endl << endl;
    
    cout << "Testing Search!" << endl << endl;
    TestSearch(666, testNode);
    cout << "Done!" << endl << endl;
    
    cout << "Testing FindSuccessor!" << endl << endl;
    TestFindSuccessor(testNode, 42);
    cout << "Done!" << endl << endl;
    
    cout << "Testing FindingPredeccessor!" << endl << endl;
    TestFindPredecessor(testNode, 8);
    cout << "Done!" << endl << endl;
    
    cout << "Testing InorderTraverse!" << endl << endl;
    TestInorderTraverse(testNode);
    cout << "Done!" << endl << endl;
    
    cout << "Testing Delete!" << endl << endl;
    TestDelete(6, testNode);
    cout << "Done!" << endl << endl;
    
    return 0;
}

void TestInsert(int testValues[], int testListSize, BST& rootNode)
{
    int insertionValue;
    
    for(int i = 0; i < testListSize; i++)
    {
        insertionValue = testValues[i];
        rootNode.Insert(insertionValue);
    }
}

void TestSearch(int searchValue, BST& tester)
{
    bool rv;
    
    rv = tester.Search(searchValue);
    
    if(rv)
    {
        cout << "Key value is in list!" << endl;
    }
    else
    {
        cout << "Value is not in Binary Search Tree!" << endl;
    }
}

void TestFindSuccessor(BST& tester, int successItem)
{
    tester.FindSuccessor(successItem);
}

void TestFindPredecessor(BST& tester, int predItem)
{
    tester.FindPredecessor(predItem);
}

void TestInorderTraverse(BST& tester)
{
    tester.InorderTraverse();
}

void TestDelete(int deletionValue, BST& tester)
{
    tester.Delete(deletionValue);
}
