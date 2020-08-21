/*
//Bruce Conrad
//This is the Client Program for analyzing the various sorting algorithms
//CSCI 385 TR Class
//Hillman
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void RandomizeNumbers(int* ary, int listSize);
//Narrative: Randomizes numbers for the arrays to use for the sorts
//Pre-condition: user input indicates this function will be run, all list sizes
//are the same when this function is called
//Post-condition: numbers have been randomized for use in the arrays

void RunSelectionSort(int* ary, int listSize, int& comparisons, int& swaps);
//Narrative: Runs the selection sort on the selection array
//Pre-condition: selection array has been populated with values
//Post-condition: selection sort has been performed on selection array

void RunHeapSort(int* ary, int listSize, int& comparisons, int& swaps);
//Narrative: Runs the heap sort on the heap array
//Pre-condition: heap array has been populated with values
//Post-condition: heap sort has been performed on the heap array

void RunQuickSort(int* ary, int listSize, int low, int high,
                  int& comparisons, int& swaps);
//Narrative: Runs the quick sort on the quick array
//Pre-condition: quick array has been populated with values
//Post-condition: quick sort has been performed on the quick array

void RunAlgorithmSort(int* ary, int listSize);
//Narrative: Runs the built-in C++ sort for comparison
//Pre-condition: All other sorts have been run
//Post-condition: The built-in C++ sort has been run for comparison

void PopulateArrays(int* ary1, int listSize1, int* ary2, int listSize2,
                    int* ary3, int listSize3, int* ary4, int listSize4,
                    ifstream& inFile);
//Narrative: reads in data from a file and populates all arrays with this data
//Pre-condition: RandomizeNumbers not called, all list sizes are the same when
//this function is called
//Post-condition: all arrays have been populated with values

void Swap(int* ary, int listSize, int index1, int index2);
//Narrative: swaps two numbers in terms of their index within that array
//Pre-condition: Selection Sort is being performed, indices are valid
//within the array
//Post-condition: two numbers have been swapped within the array passed in

void HeapifyDown(int* ary, int listSize, int index, int& comparisons, int& swaps);
//Narrative: Readjusts the heap array properly to maintain heap property
//Pre-condition: Heap Sort is being performed
//Post-condition: Heap is properly sorted as a max heap, heap property
//is maintained

int Partition(int* ary, int listSize, int low, int high, int& comparisons, int& swaps);
//Narrative: Partitions the list into subsections
//Pre-condition: Quick Sort is being performed
//Post-condition: Partition has been created

void PrintArraysDawg(int* ary, int listSize);
//Narrative: Prints the arrays in the current order
//Pre-condition: none
//Post-condition: Array has been printed in the current order


int main()
{
    int* selectionArray = NULL;
    int* heapArray = NULL;
    int* quickArray = NULL;
	int* compArray = NULL;
    
    int selectionComp = 0;
    int heapComp = 0;
    int quickComp = 0;
    int selectionSwap = 0;
    int heapSwap = 0;
    int quickSwap = 0;
    
    ifstream inputFile;
    string fileName;
    
    int listSize1;
    int listSize2;
    int listSize3;
	int listSize4;
    int commonListSize;
    
    char response;
    string inputFileNumString;
    int inputFileNumInt;
    
    int i = 0;
    int low;
    int high;
    
    cout << "Enter the common list size: ";
    cin >> commonListSize;
    
    listSize1 = commonListSize;
    listSize2 = commonListSize;
    listSize3 = commonListSize;
	listSize4 = commonListSize;
    
    selectionArray = new int [listSize1];
    heapArray = new int [listSize2];
    quickArray = new int [listSize3];
	compArray = new int [listSize4];
	
    
    low = 0;
    high = listSize3 - 1;
    
    cout << "Would you like to randomize the numbers to sort? (Y or N)";
    cin >> response;
    
    if(response == 'Y')
    {
        RandomizeNumbers(selectionArray, listSize1);
        RandomizeNumbers(heapArray, listSize2);
        RandomizeNumbers(quickArray, listSize3);
		RandomizeNumbers(compArray, listSize4);
    }
    
    else
    {
        cout << "Enter the input file name: ";
        cin >> fileName;
        
        inputFile.open(fileName.c_str());
        
        PopulateArrays(selectionArray, listSize1, heapArray, listSize2,
                       quickArray, listSize3, compArray, listSize4, inputFile);
    }
    
    PrintArraysDawg(selectionArray, listSize1);
    PrintArraysDawg(heapArray, listSize2);
    PrintArraysDawg(quickArray, listSize3);
	PrintArraysDawg(compArray, listSize4);
    
    cout << "Running the Selection Sort!" << endl;
    RunSelectionSort(selectionArray, listSize1, selectionComp, selectionSwap);
    
    cout << "Running the Heap Sort!" << endl;
    RunHeapSort(heapArray, listSize2, heapComp, heapSwap);
    
    cout << "Running the Quick Sort!" << endl;
    RunQuickSort(quickArray, listSize3, low, high, quickComp, quickSwap);
	
	cout << "Running the Built-in Sort" << endl;
	RunAlgorithmSort(compArray, listSize4);
    
    inputFile.close();
    
    cout << "Printing Sorted Selection Array and Stats!" << endl;
    PrintArraysDawg(selectionArray, listSize1);
    cout << "Comparisons: " << selectionComp << endl;
    cout << "Swaps: " << selectionSwap << endl;
    
    cout << "Printing Sorted Heap Array and Stats!" << endl;
    PrintArraysDawg(heapArray, listSize2);
    cout << "Comparisons: " << heapComp << endl;
    cout << "Swaps: " << heapSwap << endl;
    
    cout << "Printing Sorted Quick Array and Stats!" << endl;
    PrintArraysDawg(quickArray, listSize3);
    cout << "Comparisons: " << quickComp << endl;
    cout << "Swaps: " << quickSwap << endl;
    
    cout << "Printing Sorted Comp Array!" << endl;
	PrintArraysDawg(compArray, listSize4);
    
    
    delete[] selectionArray;
    selectionArray = NULL;
    
    delete[] heapArray;
    heapArray = NULL;
    
    delete[] quickArray;
    quickArray = NULL;
    
    delete[] compArray;
    compArray = NULL;
    
    return 0;
}

void RandomizeNumbers(int* ary, int listSize)
{
    int randomNumber;
    srand(time(NULL));
    
    for(int i = 0; i < listSize; i++)
    {
        randomNumber = rand()%listSize + 1;
        
        ary[i] = randomNumber;
    }
}

void RunSelectionSort(int* ary, int listSize, int& comparisons, int& swaps)
{
    int minIndex;
    
    for(int i = 0; i <= listSize - 2; i++)
    {
        minIndex = i;
        
        for(int j = i + 1; j <= listSize - 1; j++)
        {
            comparisons++;
            if(ary[j] < ary[minIndex])
            {
                minIndex = j;
            }
        }
        
        if(minIndex != i)
        {
            Swap(ary, listSize, i, minIndex);
            swaps++;
        }
    }
}

void RunHeapSort(int* ary, int listSize, int& comparisons, int& swaps)
{
    for(int i = listSize/2 - 1; i >= 0; i--)
    {
        HeapifyDown(ary,listSize, i, comparisons, swaps);
    }
    
    for(int i = listSize -1; i >= 0; i--)
    {
        Swap(ary, listSize, 0, i);
        swaps++;
        HeapifyDown(ary, i, 0, comparisons, swaps);
    }
}

void RunQuickSort(int* ary, int listSize, int low, int high,
                  int& comparisons, int& swaps)
{
    int partitionIndex;
    
    if(low < high)
    {
        comparisons++;
        partitionIndex = Partition(ary, listSize, low, high, comparisons, swaps);
        
        RunQuickSort(ary, listSize, low, partitionIndex-1, comparisons, swaps);
        RunQuickSort(ary, listSize, partitionIndex+1, high, comparisons, swaps);
    }
}

void RunAlgorithmSort(int* ary, int listSize)
{
	sort(ary, ary + listSize);
}

void PopulateArrays(int* ary1, int listSize1, int* ary2, int listSize2,
                    int* ary3, int listSize3, int* ary4, int listSize4, ifstream& inFile)
{
    string numFromFileString;
    int numFromFileInt;
    int i = 0;
    
    getline(inFile, numFromFileString);
    while(!inFile.eof())
    {
        numFromFileInt = stoi(numFromFileString, nullptr);
        ary1[i] = numFromFileInt;
        ary2[i] = numFromFileInt;
        ary3[i] = numFromFileInt;
		ary4[i] = numFromFileInt;
        i++;
        getline(inFile, numFromFileString);
    }
}

void Swap(int* ary, int listSize, int index1, int index2)
{
    int temp = ary[index2];
    ary[index2] = ary[index1];
    ary[index1] = temp;
}

void HeapifyDown(int* ary, int listSize, int index, int& comparisons, int& swaps)
{
    int largestValue = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;
    
    comparisons++;
    if(leftChild < listSize && ary[leftChild] > ary[largestValue])
    {
        largestValue = leftChild;
    }
    
    comparisons++;
    if(rightChild < listSize && ary[rightChild] > ary[largestValue])
    {
        largestValue = rightChild;
    }
    
    comparisons++;
    if(largestValue != index)
    {
        Swap(ary, listSize, index, largestValue);
        swaps++;
        HeapifyDown(ary, listSize, largestValue, comparisons, swaps);
    }
}

int Partition(int* ary, int listSize, int low, int high, int& comparisons, int& swaps)
{
    int pivot = ary[low];
    
    do
    {
        while(low < high && ary[high] >= pivot)
        {
            high = high - 1;
            comparisons++;
        }
        
        if(low < high)
        {
            ary[low] = ary[high];
            swaps++;
            
            while(low < high && ary[low] <= pivot)
            {
                low = low + 1;
                comparisons++;
            }
            
            if(low < high)
            {
                ary[high] = ary[low];
                swaps++;
            }
        }
    }
    while(low < high);
    
    if(pivot != ary[low])
    {
        ary[low] = pivot;
        swaps++;
    }
    
    return(low);
}

void PrintArraysDawg(int* ary, int listSize)
{
    for(int i = 0; i < listSize; i++)
    {
        cout << ary[i] << ", ";
    }
    
    cout << endl;
}
