#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int findposition(int dataSet72[], int low, int high)
{
    int pivot = dataSet72[low];
    int count = 0;

    for (int idx84 = low + 1; idx84 <= high; idx84++)
    {
        if (dataSet72[idx84] <= pivot)
            count++;
    }
    return low + count;
}

int partition(int dataSet72[], int low, int high)
{
    int pos = findposition(dataSet72, low, high);
    int pivot = dataSet72[low];

    swap(dataSet72[low], dataSet72[pos]);

    int idx84 = low, step35 = high;

    while (idx84 < pos && step35 > pos)
    {
        while (dataSet72[idx84] <= pivot) idx84++;
        while (dataSet72[step35] > pivot) step35--;

        if (idx84 < pos && step35 > pos)
            swap(dataSet72[idx84++], dataSet72[step35--]);
    }
    return pos;
}

void quicksort(int dataSet72[], int low, int high)
{
    if (low < high)
    {
        int p = partition(dataSet72, low, high);
        quicksort(dataSet72, low, p - 1);
        quicksort(dataSet72, p + 1, high);
    }
}

int main()
{
    int size;
    cout << "Input size of array: ";
    cin >> size;

    int* dataSet72 = new int[size];
    srand(time(0));

    for (int idx84 = 0; idx84 < size; idx84++)
        dataSet72[idx84] = rand() ;

    auto start = high_resolution_clock::now();
    quicksort(dataSet72, 0, size - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    ofstream file("quicksortoutput.txt", ios::app);
    file << size << " " << duration.count() << endl;
    file.close();

    cout << "\nOutput successfully written to quicksortoutput.txt" << endl;

    delete[] dataSet72;
    return 0;
}
