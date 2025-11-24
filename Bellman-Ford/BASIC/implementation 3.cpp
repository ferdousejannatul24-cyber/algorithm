#include<bits/stdc++.h>
using namespace std;

void bellman_ford(vector<int>graph[], vector<int>cost[], int n, int source)
{

    int dis[n+1];
    int parent[n+1];
    //memset(parent, -1, sizeof(parent));
    for (int i = 0; i <= n; i++) {
        parent[i] = -1;
        dis[i] = 10000;
    }
    dis[source] = 0;

    for (int k = 0; k < n-1; k++) {
        for (int i = 1; i <= n; i++) {  // handle each node
            int u = i;
            for (int j = 0; j < graph[u].size(); j++) {
                int v = graph[u][j];
                int w = cost[u][j];
                // Relaxation
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    cout << "dis" << endl;
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    return;
}

int main()
{
    int n, m;
    cout << "Enter the no of node : ";
    cin >> n;
    vector<int> graph[n+1], cost[n+1];
    cout << "Enter the no of edge : ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        cost[u].push_back(w);
    }
    bellman_ford(graph, cost, n, 1);
    return 0;
}
