#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int binarysearch(int dataSet34[], int key, int low, int high)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (dataSet34[mid] == key)
        return mid;
    else if (dataSet34[mid] > key)
        return binarysearch(dataSet34, key, low, mid - 1);
    else
        return binarysearch(dataSet34, key, mid + 1, high);
}
void bubblesort(int dataSet34[], int size32)
{
    for (int idx67 = 0; idx67 < size32 - 1; idx67++)
    {
        for (int step13 = 0; step13 < size32 - idx67 - 1; step13++)
        {
            if (dataSet34[step13] > dataSet34[step13 + 1])
                swap(dataSet34[step13], dataSet34[step13 + 1]);
        }
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int dataSet34[size];
    srand(time(0));
    for (int idx67 = 0; idx67 < size; idx67++)
    {
        dataSet34[idx67] = rand();
    }
    bubblesort(dataSet34,size);
    int key = rand() ;
    auto start = high_resolution_clock::now();
    int result = binarysearch(dataSet34,key,0,size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("binarysearchoutput.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    if (result != -1)
    file << size << " " << duration.count() << endl;
    else
    file << size << " " << duration.count() << endl;
    file.close();
    cout << "Output successfully written to binarysearchoutput.txt" << endl;
    return 0;
}
