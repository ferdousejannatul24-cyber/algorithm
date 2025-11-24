#include <bits/stdc++.h>
using namespace std;

string color[10];
int dis[10];
int pred[10];

void BFS(vector<int> graph[], int source, int n)
{
    for (int i = 0; i < n; i++) {
        color[i] = "w";
        dis[i] = INT_MAX;
        pred[i] = -1;
    }
    queue<int> q;
    color[source] = "g";
    dis[source] = 0;
    q.push(source);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (color[v] == "w") {
                color[v] = "g";
                dis[v] = dis[u] + 1;
                pred[v] = u;
                q.push(v);
            }
        }
        color[u] = "b";
    }
}

void path(int source, int des)
{
    if (des == -1) return;
    int parent = pred[des];
    path(source, parent);
    cout << des << " ";
}

int main()
{
    vector<int> graph[10];

    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(2);
    graph[4].push_back(2);

    BFS(graph, 0, 4);

    cout << dis[3] << endl;

    path(0, 3);

    return 0;
}
