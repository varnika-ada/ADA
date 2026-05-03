#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
struct minmax {
    int min;
    int max;
};
minmax maxormin(int dataSet16[], int low, int high) {
    minmax result, left, right;
    if (low == high) {
        result.min = result.max = dataSet16[low];
        return result;
    }
    if (high == low + 1) {
        if (dataSet16[low] < dataSet16[high]) {
            result.min = dataSet16[low];
            result.max = dataSet16[high];
        } else {
            result.min = dataSet16[high];
            result.max = dataSet16[low];
        }
        return result;
    }
    int mid = (low + high) / 2;
    left = maxormin(dataSet16, low, mid);
    right = maxormin(dataSet16, mid + 1, high);
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;
    return result;
}
int main() {
    int size62;
    cout << "Input size of array: ";
    cin >> size62;
    int dataSet16[size62];
    for (int idx82 = 0; idx82 < size62; idx82++)
    dataSet16[idx82] = rand() ;
    auto start = high_resolution_clock::now();
    maxormin(dataSet16, 0, size62 - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    ofstream file("maxormin_output.txt", ios::app);
    file << size62 << " " << duration.count() << endl;
    file.close();
    cout << "\noutput successfully written" << endl;
    return 0;
}