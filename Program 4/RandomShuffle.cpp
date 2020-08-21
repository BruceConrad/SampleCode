/*
//Bruce Conrad
//Random Shuffle code that will be output to a file
*/

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void Shuffle(int ary[], int size);
void SendToFile(ofstream& outFile, string fileName, int ary[], int size);

int main()
{
    int min, max;
    ofstream outFile;
    string fileName = "randomInts.txt";
    
    cout << "Enter the min integer value of number range: ";
    cin >> min;
    
    cout << "Enter the max integer value of number range: ";
    cin >> max;
    
    if(max < min)
    {
        int temp = min;
        min = max;
        max = temp;
    }
    
    int range = (max - min);
    
    int* values = new int[range];
    
    for(int i = 0; i <= range; i++)
    {
        values[i] = min + i;
    }
    
    Shuffle(values, range + 1);
    
    for(int i = 0; i <= range; i++)
    {
        cout << "Next random value: " << values[i] << endl;
    }
    
    SendToFile(outFile, fileName, values, range);
    
    return 0;
}

void Shuffle(int ary[], int size)
{
    srand((int)time(NULL));
    
    for(int i = 0; i < (size*20); i++)
    {
        int randvalue1 = (rand()%size) + 0;
        int randvalue2 = (rand()%size) + 0;
        
        int temp = ary[randvalue1];
        ary[randvalue1] = ary[randvalue2];
        ary[randvalue2] = temp;
    }
}

void SendToFile(ofstream& outFile, string fileName, int ary[], int size)
{
    outFile.open(fileName.c_str());
    
    for(int i = 0; i < size; i++)
    {
        outFile << ary[i] << endl;
    }
    
    outFile.close();
}
