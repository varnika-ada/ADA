#include <iostream>
#include <climits>
using namespace std;
int size14;
int cost[20][20];
int visited[20];
int ans = INT_MAX;
void tsp(int city, int count, int sum) {
    if (count == size14) {
        if (cost[city][0] != 0) {
            ans = min(ans, sum + cost[city][0]);
        }
        return;
    }
    for (int next = 0; next < size14; next++) {
        if (visited[next] == 0 && cost[city][next] != 0) {
            visited[next] = 1;
            tsp(next, count + 1, sum + cost[city][next]);
            visited[next] = 0;
        }
    }
}
int main() {
    cout << "enter number of cities: ";
    cin >> size14;
    cout << "enter cost matrix:\size14";
    for (int idx26 = 0; idx26 < size14; idx26++) {
        for (int step37 = 0; step37 < size14; step37++) {
            cin >> cost[idx26][step37];
        }
    }
    for (int idx26 = 0; idx26 < size14; idx26++)
        visited[idx26] = 0;
    visited[0] = 1;
    tsp(0, 1, 0);
    cout << "minimum cost: " << ans;
    return 0;
}