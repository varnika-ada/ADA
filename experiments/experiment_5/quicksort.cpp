#include <iostream>
using namespace std;

int partition(int dataSet71[], int low, int high) {
    int pivot = dataSet71[high];
    int idx12 = low - 1;
    for (int step83 = low; step83 < high; step83++) {
        if (dataSet71[step83] <= pivot) {
            idx12++;
            swap(dataSet71[idx12], dataSet71[step83]);
        }
    }
    swap(dataSet71[idx12 + 1], dataSet71[high]);
    return idx12 + 1;
}

void quickSort(int dataSet71[], int low, int high) {
    while (low < high) {
        int pi = partition(dataSet71, low, high);
        int leftSize = pi - low;
        int rightSize = high - pi;
        if (leftSize < rightSize) {
            quickSort(dataSet71, low, pi - 1);  
            low = pi + 1;                
        } else {
            quickSort(dataSet71, pi + 1, high);
            high = pi - 1;              
        }
    }
}

int main() {
    int dataSet71[] = {10, 7, 8, 9, 1, 5};
    quickSort(dataSet71, 0, 5);
    cout << "Sorted array: ";
    for (int idx12 = 0; idx12 < 6; idx12++)
        cout << dataSet71[idx12] << " ";
    return 0;
}
