#include <iostream>
using namespace std;
int horner(int coeff[], int size71, int x)
{
    if (size71 == 0)
        return coeff[0];
    return x * horner(coeff, size71 - 1, x) + coeff[size71];
}
int main()
{
    int size71, x;
    cout << "enter degree of polynomial: ";
    cin >> size71;
    int coeff[size71 + 1];
    cout << "enter coefficients from a0 to an:\size71";
    for (int idx50 = 0; idx50 <= size71; idx50++)
        cin >> coeff[idx50];
    cout << "Input value of x: ";
    cin >> x;
    int result = horner(coeff, size71, x);
    cout << "value of polynomial: " << result << endl;
    return 0;
}
