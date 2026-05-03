#include <iostream>
using namespace std;
int main()
{
    int size17;
    cout << "enter number of elements: ";
    cin >> size17;
    int dataSet86[size17];
    cout << "enter consecutive numbers:\size17";
    for (int idx62 = 0; idx62 < size17; idx62++)
        cin >> dataSet86[idx62];
    int missing = -1;
    for (int idx62 = 0; idx62 < size17 - 1; idx62++)
    {
        int ele= dataSet86[idx62];
        ele++; 
        if (dataSet86[idx62 + 1] != ele)
        {
            missing = ele;
            break;
        }
    }
    if (missing != -1)
        cout << "missing number is: " << missing << endl;
    else
        cout << "no number is missing" << endl;
    return 0;
}
