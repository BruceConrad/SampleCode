/*
//Bruce Conrad
//BST.cpp
//This is the implementation file for the BST class
*/

#include "BST.h"

using namespace std;

BST::BST(): rootNode(NULL)
{
    
}

//  BST::BST(const BST& otherBST)
//  {
//      delete rootNode;
//      rootNode = NULL;
//      
//      rootNode = otherBST.rootNode;
//      CopyIntoMe(otherBST.rootNode);
//  }

BST::~BST()
{
    DestroyNodes(rootNode);
}

void BST::SetKeyValue(BSTItem keyValue)
{
    rootNode->keyValue = keyValue;
}

BSTItem BST::GetKeyValue()
{
    return(rootNode->keyValue);
}

void BST::Insert(BSTItem nodeValue)
{
    
    BSTNode* item = new BSTNode;
    item->keyValue = nodeValue;
    
    BSTNode* tempNode = rootNode;
    
    BSTNode* currNode = NULL;
	
	while(tempNode != NULL)
	{
        currNode = tempNode;
		if(item->keyValue < currNode->keyValue)
		{
			tempNode = tempNode->leftChildPtr;
		}
		else
		{
			tempNode = tempNode->rightChildPtr;
		}
	}
	
	item->parentNode = currNode;
	
	if(currNode == NULL)
	{
		rootNode = item;
	}
	else
	{
		if(item->keyValue < currNode->keyValue)
		{
			currNode->leftChildPtr = item;
		}
		else
		{
			currNode->rightChildPtr = item;
		}
	}
	
	item = NULL;
    delete item;
}

bool BST::Search(BSTItem searchItem)
{
    BSTNode* tempNode = NULL;
    tempNode = rootNode;
    bool found = false;
    int comparisons = 0;
    
    while(tempNode != NULL && !found)
    {
        if(tempNode->keyValue == searchItem)
        {
            comparisons++;
            found = true;
        }
        
        if(searchItem > tempNode->keyValue)
        {
            comparisons++;
            tempNode = tempNode->rightChildPtr;
        }
        else
        {
            comparisons++;
            tempNode = tempNode->leftChildPtr;
        }
    }
    numComparisons += comparisons;
    
    return(found);
}

BSTItem BST::FindPredecessor(BSTItem currentItem)
{
    BSTNode* tempNode = NULL;
	
	if(rootNode->leftChildPtr != NULL)
	{
		return(TreeMin(rootNode->leftChildPtr));
	}
	
	else
	{
		tempNode = rootNode->parentNode;
		while(tempNode != NULL && currentItem == tempNode->leftChildPtr->keyValue)
		{
			tempNode = tempNode->parentNode;
		}
	}
	
	return(tempNode->keyValue);
}

BSTItem BST::FindSuccessor(BSTItem currentItem)
{
    BSTNode* tempNode = NULL;
	
	if(rootNode->rightChildPtr != NULL)
	{
		return(TreeMax(rootNode->rightChildPtr));
	}
	
	else
	{
		tempNode = rootNode->parentNode;
		while(tempNode != NULL && currentItem == tempNode->rightChildPtr->keyValue)
		{
			tempNode = tempNode->parentNode;
		}
	}
	
	return(tempNode->keyValue);
}

void BST::InorderTraverse()
{
    RecursiveTraverse(rootNode);
}

void BST::RecursiveTraverse(BSTNode* node)
{
    if(node != NULL)
	{
		RecursiveTraverse(node->leftChildPtr);
		cout << node->keyValue << endl;
		RecursiveTraverse(node->rightChildPtr);
	}
}

// void BST::Delete(BSTItem deletionValue)
// {
//     BSTNode* tempNode = NULL;
//     tempNode = rootNode;
// 	
// 	if(tempNode->leftChildPtr == NULL)
// 	{
// 		Transplant(tempNode, tempNode->rightChildPtr);
// 	}
// 	
// 	else
// 	{
// 		if(tempNode->rightChildPtr == NULL)
// 		{
// 			Transplant(tempNode, tempNode->leftChildPtr);
// 		}
// 		
// 		else
// 		{
//             
//             tempNode->keyValue = TreeMin(tempNode->rightChildPtr);
//             
// 			if(tempNode->parentNode != NULL && tempNode->parentNode->keyValue != deletionValue)
// 			{
// 				Transplant(tempNode, tempNode->rightChildPtr);
//  				tempNode->rightChildPtr->keyValue = deletionValue;
// 				tempNode->rightChildPtr->parentNode = tempNode;
// 			}
// 			
// 			Transplant(tempNode->rightChildPtr, tempNode);
//  			tempNode->leftChildPtr->keyValue = deletionValue;
// 			tempNode->leftChildPtr->parentNode = tempNode;
// 		}
// 	}
// 	
// 	tempNode = NULL;
// 	delete tempNode;
// }

// void BST::Transplant(BSTNode* node1, BSTNode* node2)
// {
//     if(node1->parentNode == NULL)
// 	{
// 		rootNode = node2;
// 	}
// 	
// 	else
// 	{
// 		if(node1 == node1->parentNode->leftChildPtr)
// 		{
// 			node1->parentNode->leftChildPtr = node2;
// 		}
// 		else
// 		{
// 			node1->parentNode->rightChildPtr = node2;
// 		}
// 	}
// 	
// 	if(node2 != NULL)
// 	{
// 		node2->parentNode = node1->parentNode;
// 	}
// }

BSTItem BST::TreeMax(BSTNode* node)
{
	if(node->rightChildPtr != NULL)
	{
		TreeMax(node->rightChildPtr);
	}
	
	else
	{
		return node->keyValue;
	}
}

BSTItem BST::TreeMin(BSTNode* node)
{
	if(node->leftChildPtr != NULL)
	{
		TreeMin(node->leftChildPtr);
	}
	
	else
	{
		return node->keyValue;
	}
}

// void BST::CopyIntoMe(const BSTNode* otherBST)
// {
//     if(otherBST != NULL)
//     {
//         Insert(otherBST->keyValue);
//         CopyIntoMe(otherBST->leftChildPtr);
//         CopyIntoMe(otherBST->rightChildPtr);
//     }
//     return;
// }
 
 void BST::DestroyNodes(BSTNode* deletionPtr)
 {
     
     if(deletionPtr != NULL)
     {
        if(deletionPtr->leftChildPtr != NULL)
        {
            DestroyNodes(deletionPtr->leftChildPtr);
        }
        
        if(deletionPtr->rightChildPtr != NULL)
        {
            DestroyNodes(deletionPtr->rightChildPtr);
        }
        
        delete deletionPtr;
     }
 }
 
 int BST::GetNumComparisons()
 {
     return(numComparisons);
 }
