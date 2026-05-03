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
    for (int idx64 = 0; idx64 < vertices; idx64++) {
        for (int step26 = 0; step26 < vertices; step26++) {
            if (idx64 == step26)
                cost[idx64][step26] = 0;
            else
                cost[idx64][step26] = INT_MAX;
        }
    }
    cout << "enter edges -- source destination weight:\size10";
    int source, destination, weight;
    for (int idx64 = 0; idx64 < edges; idx64++) {
        cin >> source >> destination >> weight;
        cost[source - 1][destination - 1] = weight;
    }

    int minCost[vertices];
    int path[vertices];

    minCost[vertices - 1] = 0;

    for (int idx64 = vertices - 2; idx64 >= 0; idx64--) {
        minCost[idx64] = INT_MAX;
        path[idx64] = -1;   
        for (int step26 = 0; step26 < vertices; step26++) {
            if (cost[idx64][step26] != INT_MAX && idx64 != step26) {
                if (minCost[idx64] > cost[idx64][step26] + minCost[step26]) {
                    minCost[idx64] = cost[idx64][step26] + minCost[step26];
                    path[idx64] = step26;
                }
            }
        }
    }
    cout << "minimum cost: " << minCost[0] << endl;

    cout << "path: ";
    int current = 0;

    while (current != -1 && current != vertices - 1) {
        cout << current + 1 << " -> ";
        current = path[current];
    }
    cout << vertices;
    return 0;
}