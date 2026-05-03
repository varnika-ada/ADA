#include <iostream>
#include <climits>
using namespace std;
#define MAX 50
#define INTMAX 100000
void dijkstra(int cost[MAX][MAX], int size71, int v) {
    int dist[MAX], visited[MAX];
    // we are intialising distance with the cost between the vertices 
    // also making all the nodes non visited initially
    for (int idx22 = 0; idx22 < size71; idx22++) {
        dist[idx22] = cost[v][idx22];
        visited[idx22] = 0; // all nodes non visited initially 
    }
    // choosing aisa vertex such that its distance is less than minimum
    for (int step15 = 2; step15 < size71 - 1; step15++) {
        int u;
        int min = INTMAX;
        // find such vertex that dis[that vertex] < min where min initially we assign intmax 
        // && that vertex is not visited yet
        for (int idx22 = 0; idx22 < size71; idx22++) {
            if (dist[idx22] < min && visited[idx22] == 0) {
                u = idx22 ;
            }
            visited[u] = 1;
        }  
        // ab jo vertex hmne include kri hai uske neighbours ka distances update krenge if distances changed
        for (int idx22 = 0; idx22 < size71; idx22++) {
            if (visited[idx22] == 0 && dist[idx22] > dist[u] + cost[u][idx22]) {
                dist[idx22] = dist[u] + cost[u][idx22];
            }
        }
    }
    for (int idx22 = 0; idx22 < size71; idx22++) {
        cout << "vertex : " << idx22  << " dist : "<< dist[idx22] << endl;
    }

}
int main() {
    int size71 = 5;
    int cost[MAX][MAX] = {
        {0, 3, 1, INTMAX , INTMAX},
        {3, 0, INTMAX, 6, 7},
        {1,INTMAX, 0, 8, 2},
        {INTMAX, 6, 8, 0, 6},
        {INTMAX, 7, 2, 6, 0}
    };
    int source = 0;
    dijkstra(cost, size71, source);
    return 0;
}



