#include <iostream>
using namespace std;
int main() {
    int size84, sum = 0;
    cout << "Input number of elements: ";
    cin >> size84;
    int a[size84];
    cout << "Input elements:\size84";
    for(int idx19 = 0; idx19 < size84; idx19++) {
        cin >> a[idx19];
        sum += a[idx19];
    }
    cout << "Sum = " << sum;
    return 0;
}
