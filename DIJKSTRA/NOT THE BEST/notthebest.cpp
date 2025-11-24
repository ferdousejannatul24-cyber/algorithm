#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

using weight_t = long long;
using edge = pair<int, weight_t>;
using state = pair<weight_t, int>;

void solve_case(int case_num) {
    int n, r;
    cin >> n >> r;

    vector<vector<edge>> adj(n + 1);
    for (int i = 0; i < r; ++i) {
        int u, v;
        weight_t w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    const weight_t INF = 1e18;
    vector<weight_t> d1(n + 1, INF);
    vector<weight_t> d2(n + 1, INF);
    priority_queue<state, vector<state>, greater<state>> pq;

    d1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > d2[u]) {
            continue;
        }

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            weight_t w = neighbor.second;
            weight_t new_dist = d + w;

            if (new_dist < d1[v]) {
                d2[v] = d1[v];
                d1[v] = new_dist;
                pq.push({d1[v], v});
                if (d2[v] != INF) {
                    pq.push({d2[v], v});
                }
            } else if (new_dist > d1[v] && new_dist < d2[v]) {
                d2[v] = new_dist;
                pq.push({d2[v], v});
            }
        }
    }

    cout << "Case " << case_num << ": " << d2[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    for (int i = 1; i <= t; ++i) {
        solve_case(i);
    }

    return 0;
}
