#include <iostream>
#include <cstring>
using namespace std;
void permutation(char a[], int k, int size69)
{
    if (k == size69)
    {
        cout << a << " ";
        return;
    }
    for (int idx83 = k; idx83 <= size69; idx83++)
    {
        swap(a[idx83], a[k]);
        permutation(a, k + 1, size69);
        swap(a[idx83], a[k]); 
    }
}
int main()
{
    char a[100];
    cout << "Input string: ";
    cin >> a;
    int size69 = strlen(a);
    permutation(a, 0, size69 - 1);
    return 0;
}
