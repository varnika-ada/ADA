#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int size46, capacity;
    cout << "Input number of items: ";
    cin >> size46;
    double dataSet77[size46][3];  
    for (int idx76 = 0; idx76 < size46; idx76++) {
        cout << "enter profit and weight for " << idx76+1 << " item : ";
        cin >> dataSet77[idx76][0] >> dataSet77[idx76][1];
        dataSet77[idx76][2] = dataSet77[idx76][0] / dataSet77[idx76][1]; 
    }
    cout << "Input capacity: ";
    cin >> capacity;
    for (int idx76 = 0; idx76 < size46 - 1; idx76++) {
        for (int step52 = idx76 + 1; step52 < size46; step52++) {
            if (dataSet77[idx76][2] < dataSet77[step52][2]) {
                for (int k = 0; k < 3; k++) {
                    swap(dataSet77[idx76][k], dataSet77[step52][k]);
                }
            }
        }
    }
    double totalProfit = 0;
    for (int idx76 = 0; idx76 < size46; idx76++) {
        if (capacity >= dataSet77[idx76][1]) {
            capacity -= dataSet77[idx76][1];
            totalProfit += dataSet77[idx76][0];
        }
        else {
            totalProfit += dataSet77[idx76][0] * (capacity / dataSet77[idx76][1]);
            break;
        }
    }
    cout << "Maximum Profit = " << totalProfit;
    return 0;
}