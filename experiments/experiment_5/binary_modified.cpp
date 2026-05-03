#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int binarysearch(int dataSet74[], int key, int low, int high)
{
    if (low > high)
    return -1;
    int mid = low + (high - low) / 3;
    if (dataSet74[mid] == key)
    return mid;
    else if (dataSet74[mid] > key)
    return binarysearch(dataSet74, key, low, mid - 1);
    else
    return binarysearch(dataSet74, key, mid + 1, high);
}
void bubblesort(int dataSet74[], int size75)
{
    for (int idx79 = 0; idx79 < size75 - 1; idx79++)
    {
        for (int step34 = 0; step34 < size75 - idx79 - 1; step34++)
        {
            if (dataSet74[step34] > dataSet74[step34 + 1])
                swap(dataSet74[step34], dataSet74[step34 + 1]);
        }
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int dataSet74[size];
    cout << "enter array elements";
    for (int idx79 = 0; idx79 < size; idx79++)
    {
       cin >> dataSet74[idx79];
    }
    int key ;
    cout << "enter key";
    cin >> key ;
    bubblesort(dataSet74,size);
    int result = binarysearch(dataSet74,key,0,size);
    if ( result == -1)
    cout << "element not found";
    else
    cout << "element found";
    return 0;
}

