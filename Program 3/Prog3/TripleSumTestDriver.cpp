/*Bruce Conrad
//TripleSum Program
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>

using namespace std;

int TripleSumFunction(int listSize, int* sumArray);
//Narrative: function implementation of the TripleSum algorithm
//Pre-condition: list of integers is non-empty
//Post-condition: a list of triples that count to zero has been calculated

void CreateRandomNumbers(int* sumArray, int& listSize);
//Narrative: creates a random list of numbers of size N
//Pre-condition: none
//Post-condition: a list of size N is populated with random integers

time_t TimeClock(int* sumArray, int listSize);
//Narrative: times the run-time of the TripleSum function
//Pre-condition: none
//Post-condition: run-time of the TripleSum function has been calculated

int main()
{
    time_t totalTime;
    int* tripleSumArrayPtr;
    int testListSize;
    
    cout << "Enter the test list size: ";
    cin >> testListSize;
    
	if(testListSize <= 128000)
	{
		tripleSumArrayPtr = new int [testListSize];
		
		CreateRandomNumbers(tripleSumArrayPtr, testListSize);
		
		totalTime = TimeClock(tripleSumArrayPtr, testListSize);
		
		cout << "TripleSum Runtime is: " << totalTime << " seconds" << endl;
		
		delete[] tripleSumArrayPtr;
    }
	
	else
	{
		cout << "Invalid list size per Program specs--terminating program run!" << endl;
		return(1);
	}
	
    return(0);
}

int TripleSumFunction(int listSize, int* sumArray)
{
    int count = 0;
    int i = 0;
    int j;
    int k;
    
    while(i < listSize)
    {
        j = i + 1;
        
        while(j < listSize)
        {
            k = j + 1;
            
            while(k < listSize)
            {
                if(sumArray[i] + sumArray[j] + sumArray[k] == 0)
                {
                    count = count + 1;
					cout << "Numbers: " << sumArray[i] << " ";
					cout << sumArray[j] << " " << sumArray[k] << endl;
					cout << "Triple Sum found!" << endl;
                }
				else
				{
					cout << "Numbers: " << sumArray[i] << " ";
					cout << sumArray[j] << " " << sumArray[k] << endl;
					cout << "Triple Sum not found!" << endl;
				}
                k = k + 1;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return(count);
}

void CreateRandomNumbers(int* sumArray, int& listSize)
{
    int randomNumberGenerator;
    
    for(int i = 0; i < listSize; i++)
    {
        randomNumberGenerator = rand() % 20000 - 10000;
        sumArray[i] = randomNumberGenerator;
		cout << "Random number generated for slot " << i << " is ";
		cout << sumArray[i] << endl;
    }
    
}

time_t TimeClock(int* sumArray, int listSize)
{
    time_t startTime, endTime;
    int totalTripSums;
    time_t totalTime;
    
    time(&startTime);
    
    totalTripSums = TripleSumFunction(listSize, sumArray);
    
    time(&endTime);
    
	cout << "Total number of Triple Sums: " << totalTripSums << endl;
	
    totalTime = difftime(endTime, startTime);
    
    return(totalTime);
}
