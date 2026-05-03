#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
void insertionsort(int dataSet17[], int size20)
{
    for (int idx76 = 1; idx76 < size20; idx76++)
    {
        int key = dataSet17[idx76];
        int step22 = idx76 - 1;
        while (step22 >= 0 && dataSet17[step22] > key)
        {
            dataSet17[step22 + 1] = dataSet17[step22];
            step22--;
        }
        dataSet17[step22 + 1] = key;
    }
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int dataSet17[size];
    srand(time(0));
    for (int idx76 = 0; idx76 < size; idx76++)
        dataSet17[idx76] = rand() % 100;
    auto start = high_resolution_clock::now();
    insertionsort(dataSet17, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("insertion_output.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    file << size << " " << duration.count() << endl;
    cout << "Output successfully written to insertion_output.txt" << endl;
    return 0;
}
