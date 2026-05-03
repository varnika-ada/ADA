#include <iostream>
using namespace std;
int power(int x, int size41) {
    if (size41 == 0)
    return 1;
    return x * power(x, size41 - 1);
}
int main() {
    int x,size41,result=1;
    cout << "enter value of x : ";
    cin >> x;
    cout << "enter value of size41 : ";
    cin >> size41;
    cout << "result = " << power(x,size41);
    return 0;
}