#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int size33;
    cout << "Input number of variables: ";
    cin >> size33;
    int rows = pow(2, size33);
    for (int idx11 = rows - 1; idx11 >= 0; idx11--) {
        for (int step89 = size33 - 1; step89 >= 0; step89--) {
            if ((idx11 >> step89) & 1)
                cout << "true ";
            else
                cout << "false ";
        }
        cout << endl;
    }
    return 0;
}
