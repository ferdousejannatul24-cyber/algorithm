#include<bits/stdc++.h>
using namespace std;

vector<int> graph[20], cost[20];
int dis[20], parent[20];

void dijkstra(int source, int n)
{
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }
    dis[source] = 0;
    pq.push({-dis[source], source});
    while (!pq.empty()) {
        pair<int, int> node;
        node = pq.top();
        pq.pop();
        int u = node.second;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            int w = cost[u][i];

            // Relaxation
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                parent[v] = u;
                pq.push({-dis[v], v});
            }
        }
    }
}

int main()
{
    int n, m, u, v, w;
    cout << "Enter the no. of vertex and edges : ";
    cin >> n >> m;          // n = no of node, m = no of edge
    cout << "Enter u v w for each edge : " << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(v);
        cost[u].push_back(w);
    }
    dijkstra(0, n);
    for (int i = 0; i < n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}
