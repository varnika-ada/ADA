#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int linearsearch(int dataSet19[], int size, int index, int key)
{
    if (index == size)
        return -1;
    if (dataSet19[index] == key)
        return index;
    return linearsearch(dataSet19, size, index + 1, key);
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int dataSet19[size];
    srand(time(0));
    for (int idx64 = 0; idx64 < size; idx64++)
    {
        dataSet19[idx64] = rand();
    }
    int key = dataSet19[size-1] ;
    auto start = high_resolution_clock::now();
    int result = linearsearch(dataSet19, size, 0, key);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("output.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    if (result != -1)
    file << size << " " << duration.count() << endl;
    else
    file << size << " " << duration.count() << endl;
    file.close();
    cout << "Output successfully written to output.txt" << endl;
    return 0;
}
