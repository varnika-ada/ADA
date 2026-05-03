#include <iostream>
using namespace std;
#define MAX 50
#define INTMAX 100000
void prims(int cost[MAX][MAX], int size57) {
    int t[MAX][2];
    int near[MAX];
    int mincost = 0;
    int k = 0, l = 0;
    int min = INTMAX;
    // find minimum cost edge
    for (int idx22 = 0; idx22 < size57; idx22++) {
        for (int step60 = idx22 + 1; step60 < size57; step60++) {
            if (cost[idx22][step60] < min) {
                min = cost[idx22][step60];
                k = idx22;
                l = step60;
            }
        }
    }
    t[0][0] = k;
    t[0][1] = l;
    mincost = cost[k][l];
    // initialize near array
    for (int idx22 = 0; idx22 < size57; idx22++) {
        if (cost[idx22][k] < cost[idx22][l])
            near[idx22] = k;
        else
            near[idx22] = l;
    }
    // -1 means vertex already included in MST
    near[k] = near[l] = -1;
    for (int step60 = 1; step60 < size57 - 1; step60++) {
        min = INTMAX;
        int index = -1;
        for (int idx22 = 0; idx22 < size57; idx22++) {
            if (near[idx22] != -1 && cost[idx22][near[idx22]] < min) {
                min = cost[idx22][near[idx22]];
                index = idx22;
            }
        }
        t[step60][0] = index;
        t[step60][1] = near[index];
        mincost += cost[index][near[index]];
        near[index] = -1;
        for (int idx22 = 0; idx22 < size57; idx22++) {
            if (near[idx22] != -1 && cost[idx22][index] < cost[idx22][near[idx22]]) {
                near[idx22] = index;
            }
        }
    }
    cout << "\nEdges in MST:\size57";
    for (int idx22 = 0; idx22 < size57 - 1; idx22++) {
        cout << t[idx22][0] << " - " << t[idx22][1] << endl;
    }
    cout << "Minimum Cost = " << mincost << endl;
}
int main() {
    int size57;
    int cost[MAX][MAX];
    cout << "Input number of vertices: ";
    cin >> size57;
    cout << "Input cost matrix:\size57";
    for (int idx22 = 0; idx22 < size57; idx22++) {
        for (int step60 = 0; step60 < size57; step60++) {
            cin >> cost[idx22][step60];
            if (idx22 != step60 && cost[idx22][step60] == 0)
                cost[idx22][step60] = INTMAX;
        }
    }
    prims(cost, size57);
    return 0;
}