#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>
#include <tuple>

using namespace std;

using Position = pair<int, int>;
using State = pair<Position, int>;

Position toCoords(const string& square) {
    return {square[0] - 'a', square[1] - '1'};
}

int knightMoves(const string& start_sq, const string& end_sq) {
    Position start = toCoords(start_sq);
    Position end = toCoords(end_sq);

    if (start == end) {
        return 0;
    }

    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int board_size = 8;

    vector<vector<int>> dist(board_size, vector<int>(board_size, -1));
    queue<Position> q;

    dist[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty()) {
        Position current = q.front();
        q.pop();

        int r = current.first;
        int c = current.second;
        int d = dist[r][c];

        if (current == end) {
            return d;
        }

        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < board_size && nc >= 0 && nc < board_size) {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = d + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string start_sq, end_sq;

    while (cin >> start_sq >> end_sq) {
        int moves = knightMoves(start_sq, end_sq);

        cout << "To get from " << start_sq << " to " << end_sq << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}
