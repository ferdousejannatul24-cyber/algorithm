#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

using weight_t = long long;
using edge = pair<int, weight_t>;
using state = pair<weight_t, int>;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<edge>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        weight_t w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    const weight_t INF = 1e18;
    vector<weight_t> dist(n + 1, INF);
    vector<int> parent(n + 1, 0);
    priority_queue<state, vector<state>, greater<state>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            weight_t w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        int current = n;
        while (current != 0) {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
