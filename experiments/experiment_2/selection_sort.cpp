#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
void selectionsort(int dataSet70[], int size52)
{
    for (int idx39 = 0; idx39 < size52 - 1; idx39++)
    {
        int minindex = idx39;
        for (int step91 = idx39 + 1; step91 < size52; step91++)
        {
            if (dataSet70[step91] < dataSet70[minindex])
                minindex = step91;
        }
        swap(dataSet70[idx39], dataSet70[minindex]);
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int dataSet70[size];
    srand(time(0));
    for (int idx39 = 0; idx39 < size; idx39++)
        dataSet70[idx39] = rand() % 100;
    auto start = high_resolution_clock::now();
    selectionsort(dataSet70, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("selection_output.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    file << size << " " << duration.count() << endl;
    cout << "Output successfully written to selection_output.txt" << endl;
    return 0;
}
