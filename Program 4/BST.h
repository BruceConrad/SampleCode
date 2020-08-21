/*
//Bruce Conrad
//BST.h
//This is the header file for the BST class
*/

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

typedef int BSTItem;

class BST
{
    public:
        BST();
        //Narrative: the base constructor for the BST class
        //Pre-condition: none
        //Post-condition: a BST object has been created
        
        //BST(const BST& otherBST);
        //Narrative: the copy constructor for the BST class
        //Pre-condition: none
        //Post-condition: a BST object has been deep copied
        
        ~BST();
        //Narrative: the destructor for the BST class
        //Pre-condition: none
        //Post-condition: a BST object has been deallocated properly
        
        void SetKeyValue(BSTItem keyValue);
        //Narrative: The setter for the key value
        //Pre-condition: none
        //Post-condition: key value has been set
        
        BSTItem GetKeyValue();
        //Narrative: The getter for the key value
        //Pre-condition: none
        //Post-condition: key value has been returned
        
        void Insert(BSTItem nodeValue);
        //Narrative: inserts a node into the Binary Search Tree
        //Pre-condition: none
        //Post-condition: a node has been inserted into the proper location in the
        //Binary Search Tree
        
        bool Search(BSTItem searchItem);
        //Narrative: Searches for a specific item in the Binary Search Tree
        //Pre-condition: Binary Search Tree is populated with values
        //Post-condition: Either true is returned because the value was found or
        //false is returned because the item is not in the list
        
        BSTItem FindPredecessor(BSTItem currentItem);
        //Narrative: Finds the predecessor to a specific item in the
        //Binary Search Tree
        //Pre-condition: Binary Search Tree is populated with values,
        //currentItem exists in the tree
        //Post-condition: the key value of the predecessor is returned
        
        BSTItem FindSuccessor(BSTItem currentItem);
        //Narrative: Finds the successor to a specific item in the
        //Binary Search Tree
        //Pre-condition: Binary Search Tree is populated with values,
        //currentItem exists in the tree
        //Post-condition: the key value is returned, or -1 if there
        //is no successor
        
        void InorderTraverse();
        //Narrative: outputs the key values of the Binary Search Tree in order
        //from left-most child on the lowest level to the right-most child on the
        //lowest level
        //Pre-condition: Binary Search Tree is populated with values
        //Post-condition: all nodes are output in order
        
        //void Delete(BSTItem deletionValue);
        //Narrative: Deletes an item from the Binary Search Tree
        //Pre-condition: Binary Search Tree is populated with data,
        //keyValue exists in list prior to deletion
        //Post-condition: keyValue has been deleted from Binary Search Tree,
        //all other value around keyValue have been reorganized via 
        //Transplant helper function
        
        int GetNumComparisons();
        //Narrative: Returns the total number of comparisons
        //Pre-condition: none
        //Post-condition: total number of comparisons is returned
        
    private:
        
         struct BSTNode
         {
             BSTNode* parentNode;
             BSTNode* leftChildPtr;
             BSTNode* rightChildPtr;
             BSTItem keyValue;
         };
        
        BSTNode* rootNode;
        int numComparisons = 0;
        
        //void Transplant(BSTNode* node1, BSTNode* node2);
        //Narrative: A helper function for the Delete function of the
        //Binary Search Tree class
        //Pre-condition: Delete has been called
        //Post-condition: A node has been transplanted to the proper location
        //for deletion
		
		BSTItem TreeMax(BSTNode* node);
		//Narrative: returns the max value of the binary search tree
		//based on the given node
		//Pre-condition: none
		//Post-condition: the max value has been returned
		
		BSTItem TreeMin(BSTNode* node);
		//Narrative: returns the min value of the binary search tree based on
		//the given node
		//Pre-condition: none
		//Post-condition: the min value has been returned
        
        //void CopyIntoMe(const BSTNode* otherBST);
        //Narrative: a helper function for the copy constructor and
        //overloaded assignment operator
        //Pre-condition: copy constructor or overloaded assignment operator
        //have been called
        //Post-condition: an object has been copied into another object
        
        void DestroyNodes(BSTNode* deletionPtr);
        //Narrative: a helper function for the destructor
        //Pre-condition: destructor has been called
        //Post-condition: all dynamic memory has been deallocated
        
        void RecursiveTraverse(BSTNode* node);
        //Narrative: a helper function to traverse the BST
        //Pre-condition: InorderTraverse has been called
        //Post-condition: nodes have been output in proper order
};

#endif
