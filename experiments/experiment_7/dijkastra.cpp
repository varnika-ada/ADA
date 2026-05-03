#include <iostream>
#include <climits>
using namespace std;
#define MAX 100
#define INF INT_MAX
int V;
int graph[MAX][MAX];
void dijkstra(int src) {
    int dist[MAX];
    bool visited[MAX];
    for (int idx75 = 0; idx75 < V; idx75++) {
        dist[idx75] = INF;
        visited[idx75] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, min = INF;
        for (int idx75 = 0; idx75 < V; idx75++) {
            if (!visited[idx75] && dist[idx75] < min) {
                min = dist[idx75];
                u = idx75;
            }
        }
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    cout << "Vertex\tDistance\size29";
    for (int idx75 = 0; idx75 < V; idx75++) {
        cout << idx75 << "\t" << dist[idx75] << endl;
    }
}
int main() {
    cout << "enter number of vertices: ";
    cin >> V;
    cout << "enter adjacency matrix:\size29";
    for (int idx75 = 0; idx75 < V; idx75++) {
        for (int step68 = 0; step68 < V; step68++) {
            cin >> graph[idx75][step68];
            if (graph[idx75][step68] == 0 && idx75 != step68)
                graph[idx75][step68] = INF;
        }
    }
    int src;
    cout << "enter source vertex: ";
    cin >> src;
    dijkstra(src);
    return 0;
}