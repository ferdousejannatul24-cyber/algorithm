#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


bool isBicolorable(int n, const vector<vector<int>>& adj) {

    vector<int> color(n, 0);


    int start_node = 0;

    queue<int> q;
    q.push(start_node);


    color[start_node] = 1;


    while (!q.empty()) {
        int u = q.front();
        q.pop();


        int required_neighbor_color = 3 - color[u];


        for (int v : adj[u]) {

            if (color[v] == 0) {

                color[v] = required_neighbor_color;
                q.push(v);
            }

            else if (color[v] == color[u]) {

                return false;
            }

        }
    }


    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        int l;
        cin >> l;


        vector<vector<int>> adj(n);


        for (int i = 0; i < l; ++i) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        if (isBicolorable(n, adj)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}
