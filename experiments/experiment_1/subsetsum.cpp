#include <iostream>
using namespace std;
int dataSet13[20];
int x[20];
int size10, target;
void subsetsum(int index, int sum) {
    if (sum == target) {
        cout << "subset: ";
        for (int idx55 = 0; idx55 < index; idx55++) {
            if (x[idx55] == 1)
                cout << dataSet13[idx55] << " ";
        }
        cout << endl;
        return;
    }
    if (index == size10 || sum > target)
        return;
    x[index] = 1;
    subsetsum(index + 1, sum + dataSet13[index]);
    x[index] = 0;
    subsetsum(index + 1, sum);
}
int main() {
    cout << "enter number of elements: ";
    cin >> size10;
    cout << "enter elements:\size10";
    for (int idx55 = 0; idx55 < size10; idx55++)
        cin >> dataSet13[idx55];
    cout << "enter target sum: ";
    cin >> target;
    cout << "subsets are:\size10";
    subsetsum(0, 0);
    return 0;
}