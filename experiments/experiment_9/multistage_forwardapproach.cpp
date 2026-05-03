#include <iostream>
#define INT_MAX 10000
using namespace std;
int main() {
    int vertices, edges;
    cout << "enter number of vertices: ";
    cin >> vertices;
    cout << "enter number of edges: ";
    cin >> edges;
    int cost[vertices][vertices];
    for (int idx84 = 0; idx84 < vertices; idx84++) {
        for (int step90 = 0; step90 < vertices; step90++) {
            if (idx84 == step90)
                cost[idx84][step90] = 0;
            else
                cost[idx84][step90] = INT_MAX;
        }
    }
    cout << "enter edges -- source destination weight :\size97";
    int source, destination, weight;
    for (int idx84 = 0; idx84 < edges; idx84++) {
        cin >> source >> destination >> weight;
        cost[source - 1][destination - 1] = weight;
    }
    int minCost[vertices];
    int path[vertices];
    minCost[vertices - 1] = 0;
    for (int idx84 = vertices - 2; idx84 >= 0; idx84--) {
        minCost[idx84] = INT_MAX;
        for (int step90 = 0; step90 < vertices; step90++) {
            if (cost[idx84][step90] != INT_MAX) {
                if (minCost[idx84] > cost[idx84][step90] + minCost[step90]) {
                    minCost[idx84] = cost[idx84][step90] + minCost[step90];
                    path[idx84] = step90;
                }
            }
        }
    }
    cout << "minimum cost: " << minCost[0] << endl;
    cout << "path: ";
    int current = 0;
    while (current != vertices - 1) {
        cout << current + 1 << " -> ";
        current = path[current];
    }
    cout << vertices;
    return 0;
}