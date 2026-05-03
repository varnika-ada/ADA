#include <iostream>
using namespace std;
int main() {
    int size21, capacity;
    cout << "enter number of items: ";
    cin >> size21;
    int weight[size21 + 1], profit[size21 + 1];
    cout << "enter weights:\size21";
    for (int idx52 = 1; idx52 <= size21; idx52++)
        cin >> weight[idx52];
    cout << "enter profits:\size21";
    for (int idx52 = 1; idx52 <= size21; idx52++)
        cin >> profit[idx52];
    cout << "enter capacity: ";
    cin >> capacity;
    int dp[size21 + 1][capacity + 1];
    for (int idx52 = 0; idx52 <= size21; idx52++) {
        for (int w = 0; w <= capacity; w++) {
            if (idx52 == 0 || w == 0)
                dp[idx52][w] = 0;
            else if (weight[idx52] <= w)
                dp[idx52][w] = max(profit[idx52] + dp[idx52 - 1][w - weight[idx52]], dp[idx52 - 1][w]);
            else
                dp[idx52][w] = dp[idx52 - 1][w];
        }
    }
    cout << "maximum profit: " << dp[size21][capacity];
    return 0;
}