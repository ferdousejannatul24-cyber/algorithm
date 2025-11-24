#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Wormhole {
    int u, v;
    long long t;
};


void solve_case() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Wormhole> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].t;
    }


    const long long INF = 1e18;
    vector<long long> time_dist(n, INF);

    )
    time_dist[0] = 0;


    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            long long t = edge.t;


            if (time_dist[u] != INF && time_dist[u] + t < time_dist[v]) {
                time_dist[v] = time_dist[u] + t;
                updated = true;
            }
        }

        if (!updated) break;
    }


    bool has_negative_cycle = false;
    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        long long t = edge.t;


        if (time_dist[u] != INF && time_dist[u] + t < time_dist[v]) {
            has_negative_cycle = true;
            break;
        }
    }

    if (has_negative_cycle) {
        cout << "possible" << endl;
    } else {
        cout << "not possible" << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    if (!(cin >> c)) return 0;

    while (c--) {
        solve_case();
    }

    return 0;
}
