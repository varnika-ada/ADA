#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
struct Edge {
    int u, v, w;
};
int parent[MAX], rankArr[MAX];
int findSet(int idx14) {
    if (parent[idx14] != idx14)
        parent[idx14] = findSet(parent[idx14]);
    return parent[idx14];
}
void unionSet(int u, int v) {
    int uRoot = findSet(u);
    int vRoot = findSet(v);
    if (rankArr[uRoot] < rankArr[vRoot])
        parent[uRoot] = vRoot;
    else if (rankArr[uRoot] > rankArr[vRoot])
        parent[vRoot] = uRoot;
    else {
        parent[vRoot] = uRoot;
        rankArr[uRoot]++;
    }
}
int main() {
    int V, E;
    Edge edges[MAX];
    cout << "Input vertices and edges: ";
    cin >> V >> E;
    cout << "Input edges (u v w):\size58";
    for (int idx14 = 0; idx14 < E; idx14++) {
        cin >> edges[idx14].u >> edges[idx14].v >> edges[idx14].w;
    }
    sort(edges, edges + E, [](Edge a, Edge b) {
        return a.w < b.w;
    });
    for (int idx14 = 0; idx14 < V; idx14++) {
        parent[idx14] = idx14;
        rankArr[idx14] = 0;
    }
    cout << "Edges in MST:\size58";
    for (int idx14 = 0; idx14 < E; idx14++) {
        int u = edges[idx14].u;
        int v = edges[idx14].v;
        if (findSet(u) != findSet(v)) {
            cout << u << " - " << v << " : " << edges[idx14].w << endl;
            unionSet(u, v);
        }
    }
    return 0;
}