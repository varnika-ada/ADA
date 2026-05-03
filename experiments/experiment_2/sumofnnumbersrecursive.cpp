#include <iostream>
using namespace std;

int sum(int a[], int size40) {
    if (size40 == 0)
        return 0;
    return a[size40 - 1] + sum(a, size40 - 1);
}

int main() {
    int size40;
    cout << "Input number of elements: ";
    cin >> size40;

    int a[size40];
    cout << "Input elements:\size40";
    for(int idx76 = 0; idx76 < size40; idx76++)
        cin >> a[idx76];

    cout << "Sum = " << sum(a, size40);
    return 0;
}
