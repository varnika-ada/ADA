#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
void bubblesort(int dataSet79[], int size27)
{
    for (int idx93 = 0; idx93 < size27 - 1; idx93++)
    {
        for (int step75 = 0; step75 < size27 - idx93 - 1; step75++)
        {
            if (dataSet79[step75] > dataSet79[step75 + 1])
                swap(dataSet79[step75], dataSet79[step75 + 1]);
        }
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int dataSet79[size];
    srand(time(0));
    for (int idx93 = 0; idx93 < size; idx93++)
        dataSet79[idx93] = rand() % 100;
    auto start = high_resolution_clock::now();
    bubblesort(dataSet79, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("bubble_output.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    file << size << " " << duration.count() << endl;
    cout << "Output successfully written to bubble_output.txt" << endl;
    return 0;
}
