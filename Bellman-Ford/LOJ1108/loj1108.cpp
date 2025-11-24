#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using cost_t = long long;

struct Edge {
    int u, v;
    cost_t w;
};

cost_t calculate_cost(int busyness_u, int busyness_v) {
    cost_t diff = (cost_t)busyness_v - busyness_u;
    return diff * diff * diff;
}

void solve() {
    int n;
    int set_num = 1;

    while (cin >> n) {
        // Read busyness values (1-indexed)
        vector<int> busyness(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> busyness[i];
        }

        int r; // Number of roads
        cin >> r;

        vector<Edge> edges;
        for (int i = 0; i < r; ++i) {
            int u, v;
            cin >> u >> v;
            cost_t w = calculate_cost(busyness[u], busyness[v]);
            edges.push_back({u, v, w});
        }

        int q; // Number of queries
        cin >> q;

        const cost_t INF = 1e15;
        vector<cost_t> dist(n + 1, INF);

        // Source is junction 1
        if (n >= 1) {
            dist[1] = 0;
        }

        // Bellman-Ford: N-1 passes for shortest path
        for (int i = 1; i < n; ++i) {
            for (const auto& edge : edges) {
                if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.w;
                }
            }
        }

        // Bellman-Ford: N-th pass to detect negative cycles
        vector<bool> in_negative_cycle_path(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            for (const auto& edge : edges) {
                if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                    // Update and mark as part of or reachable from a negative cycle
                    dist[edge.v] = -INF;
                    in_negative_cycle_path[edge.v] = true;
                }
            }
        }

        // Propagate the negative cycle state (optional but safer)
        for (int i = 1; i <= n; ++i) {
             for (const auto& edge : edges) {
                if (in_negative_cycle_path[edge.u] && dist[edge.u] == -INF) {
                    dist[edge.v] = -INF;
                    in_negative_cycle_path[edge.v] = true;
                }
            }
        }


        cout << "Set #" << set_num << endl;
        for (int i = 0; i < q; ++i) {
            int destination;
            cin >> destination;

            cost_t min_earning = dist[destination];

            if (min_earning >= 3 && min_earning != INF) {
                cout << min_earning << endl;
            } else {
                cout << "?" << endl;
            }
        }

        set_num++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
