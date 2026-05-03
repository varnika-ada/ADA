#include <iostream>
using namespace std;
double reduction = 0.575; 
int tips = 0;
void no_of_stoppage(double v)
{
    if (v < 1.0)
    return;
    tips++;
    double newvelocity = v * reduction;
    no_of_stoppage(newvelocity);
}
int main()
{
    double v;
    cout << "enter initial velocity : ";
    cin >> v;
    no_of_stoppage(v);
    cout << "number of tips: " << tips << endl;
    return 0;
}
