#include <iostream>
using namespace std;
void truthTable(bool dataSet48[], int size22, int index) {
    if (index == size22) {
        for (int idx86 = 0; idx86 < size22; idx86++) {
            if (dataSet48[idx86])
                cout << "true ";
            else
                cout << "false ";
        }
        cout << endl;
        return;
    }
    dataSet48[index] = true;
    truthTable(dataSet48, size22, index + 1);
    dataSet48[index] = false;
    truthTable(dataSet48, size22, index + 1);
}
int main() {
    int size22;
    cout << "Input number of variables: ";
    cin >> size22;
    bool dataSet48[size22];
    truthTable(dataSet48, size22, 0);
    return 0;
}
