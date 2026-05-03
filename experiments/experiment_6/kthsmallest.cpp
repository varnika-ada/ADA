#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int partition(int dataSet44[], int low, int high) {
    int pivot = dataSet44[high];
    int idx65 = low - 1;
    for (int step21 = low; step21 < high; step21++) {
        if (dataSet44[step21] <= pivot) {
            idx65++;
            swap(dataSet44[idx65], dataSet44[step21]);
        }
    }
    swap(dataSet44[idx65 + 1], dataSet44[high]);
    return idx65 + 1;
}
int kthsmallest(int dataSet44[], int low, int high, int k) {
    if (low <= high) {
        int p = partition(dataSet44, low, high);
        if (p == k)
            return dataSet44[p];
        else if (p > k)
            return kthsmallest(dataSet44, low, p - 1, k);
        else
            return kthsmallest(dataSet44, p + 1, high, k);
    }
    return -1; 
}
int main() {
    cout << "enter size of array : ";
    int size55;
    cin >> size55 ;
    int dataSet44 [size55];
    for (int idx65 = 0 ; idx65 < size55 ; idx65++)
    dataSet44[idx65] = rand() ;
    int k = rand()%100 ; 
    auto start = high_resolution_clock::now();
    kthsmallest(dataSet44, 0, size55 - 1, k - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    ofstream file("kthsmallest_output.txt", ios::app);
    file << size55 << " " << duration.count() << endl;
    file.close();

    cout << "\noutput successfully written" << endl;
    cout << "kth smallest element: "<< kthsmallest(dataSet44, 0, size55 - 1, k - 1);
    return 0;
}
