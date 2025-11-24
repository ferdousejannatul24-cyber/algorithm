#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;


int findMinConquests(int start, int end, int n_countries, const vector<vector<int>>& adj) {

    vector<int> dist(n_countries + 1, -1);
    queue<int> q;


    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();


        if (u == end) {
            return dist[u];
        }


        for (int v : adj[u]) {

            if (dist[v] == -1) {

                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }


    return -1;
}


void print_result(int start, int end, int conquests) {

    stringstream ss;


    ss << setw(2) << right << start;


    ss << " to ";


    ss << setw(2) << right << end;


    ss << ": ";


    ss << conquests;

    cout << ss.str() << endl;
}

int main() {

    const int N_COUNTRIES = 20;


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_set = 1;


    while (true) {
        vector<vector<int>> adj(N_COUNTRIES + 1);
        bool eof_reached = false;


        for (int i = 1; i < N_COUNTRIES; ++i) {
            int X;
            if (!(cin >> X)) {

                eof_reached = true;
                break;
            }


            for (int j = 0; j < X; ++j) {
                int J;
                cin >> J;

                adj[i].push_back(J);
                adj[J].push_back(i);
            }
        }

        if (eof_reached) {
            break;
        }


        int N;
        if (!(cin >> N)) {
            break;
        }


        cout << "Test Set #" << test_set << endl;

        for (int i = 0; i < N; ++i) {
            int A, B;
            cin >> A >> B;


            int min_conquests = findMinConquests(A, B, N_COUNTRIES, adj);


            print_result(A, B, min_conquests);
        }


        cout << endl;

        test_set++;
    }

    return 0;
}
