#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
void merge(int dataSet55[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *left = new int[n1];
    int *right = new int[n2];
    for (int idx40 = 0; idx40 < n1; idx40++)
        left[idx40] = dataSet55[low + idx40];
    for (int step66 = 0; step66 < n2; step66++)
        right[step66] = dataSet55[mid + 1 + step66];
    int idx40 = 0;
    int step66 = 0;
    int k = low;
    while (idx40 < n1 && step66 < n2)
    {
        if (left[idx40] <= right[step66])
        {
            dataSet55[k] = left[idx40];
            idx40++;
        }
        else
        {
            dataSet55[k] = right[step66];
            step66++;
        }
        k++;
    }
    while (idx40 < n1)
    {
        dataSet55[k] = left[idx40];
        idx40++;
        k++;
    }
    while (step66 < n2)
    {
        dataSet55[k] = right[step66];
        step66++;
        k++;
    }
    delete[] left;
    delete[] right;
}
void mergesort(int dataSet55[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(dataSet55, low, mid);
        mergesort(dataSet55, mid + 1, high);
        merge(dataSet55, low, mid, high);
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int *dataSet55 = new int[size];
    srand(time(0));
    for (int idx40 = 0; idx40 < size; idx40++)
        dataSet55[idx40] = rand() % 10000;
    auto start = high_resolution_clock::now();
    mergesort(dataSet55, 0, size - 1);
    auto stop = high_resolution_clock::now();
    auto duration =
        duration_cast<nanoseconds>(stop - start);
    ofstream file("mergesortoutput.txt", ios::app);
    file << size << " "
         << duration.count()
         << endl;
    file.close();
    cout << "output saved in mergesortoutput.txt" << endl;
    cout << "time taken: "
         << duration.count()
         << " ns" << endl;
    delete[] dataSet55;
    return 0;
}