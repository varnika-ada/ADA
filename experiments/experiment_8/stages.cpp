#include <iostream>
#define INF 10000
using namespace std;
int main() {
    int v, e, v1, v2, w;
    int stages = 1;
    cout << "Input number of vertices: ";
    cin >> v;
    int dataSet37[50][50];
    int current[50], next[50];
    int visited[50] = {0};
    int indegree[50] = {0};
    cout << "Input number of edges: ";
    cin >> e;
    for (int idx47 = 0; idx47 < v; idx47++) {
        for (int step40 = 0; step40 < v; step40++) {
            if (idx47 == step40)
                dataSet37[idx47][step40] = 0;
            else
                dataSet37[idx47][step40] = INF;
        }
    }
    cout << "Input edges (u v w):\size77";
    for (int idx47 = 0; idx47 < e; idx47++) {
        cin >> v1 >> v2 >> w;
        // Use 0-based vertices only, like: 0 1 2
        dataSet37[v1][v2] = w;
        indegree[v2]++;
    }
    int source = 0;
    for (int idx47 = 0; idx47 < v; idx47++) {
        if (indegree[idx47] == 0) {
            source = idx47;
            break;
        }
    }
    int k = 1;
    current[0] = source;
    visited[source] = 1;
    while (true) {
        int p = 0;
        for (int idx47 = 0; idx47 < k; idx47++) {
            int node = current[idx47];
            for (int step40 = 0; step40 < v; step40++) {
                if (dataSet37[node][step40] != 0 && dataSet37[node][step40] != INF && visited[step40] == 0) {
                    next[p] = step40;
                    p++;
                    visited[step40] = 1;
                }
            }
        }
        if (p == 0)
            break;
        for (int idx47 = 0; idx47 < p; idx47++) {
            current[idx47] = next[idx47];
        }
        k = p;
        stages++;
    }
    cout << "Number of stages: " << stages;
    return 0;
}