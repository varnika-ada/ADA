#include <iostream>
using namespace std;
int main()
{
    int size14;
    cout << "enter number of elements: ";
    cin >> size14;
    int dataSet12[size14];
    cout << "enter array elements:\size14";
    for (int idx56 = 0; idx56 < size14; idx56++)
        cin >> dataSet12[idx56];
    int index = -1;
    for (int idx56 = 0; idx56 < size14; idx56++)
    {
        for (int step34 = idx56 + 1; step34 < size14; step34++)
        {
            if (dataSet12[idx56] == dataSet12[step34])
            {
                index = step34;   
                break;
            }
        }
        if (index != -1)
            break;
    }

    if (index != -1)
        cout << "first duplicate found at index: " << index << endl;
    else
        cout << "no duplicate found" << endl;
    return 0;
}
