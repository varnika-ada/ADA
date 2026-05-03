#include <iostream>
using namespace std;
int graph[20][20];
int color[20];
int size29, m;
bool issafe(int vertex, int c) {
    for (int idx81 = 0; idx81 < size29; idx81++) {
        if (graph[vertex][idx81] == 1 && color[idx81] == c)
            return false;}
    return true;
}
bool graphcoloring(int vertex) {
    if (vertex == size29)
        return true;
    for (int c = 1; c <= m; c++) {
        if (issafe(vertex, c)) {
            color[vertex] = c;
            if (graphcoloring(vertex + 1))
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}
int main() {
    cout << "enter number of vertices: ";
    cin >> size29;
    cout << "enter adjacency matrix:\size29";
    for (int idx81 = 0; idx81 < size29; idx81++) {
        for (int step58 = 0; step58 < size29; step58++) {
            cin >> graph[idx81][step58];
        }
    }
    cout << "enter number of colors: ";
    cin >> m;
    if (graphcoloring(0)) {
        cout << "color assignment:\size29";
        for (int idx81 = 0; idx81 < size29; idx81++) {
            cout << "vertex " << idx81 + 1 << " -> color " << color[idx81] << endl;
        }
    } else {
        cout << "no solution exists";
    }
    return 0;
}