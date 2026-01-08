#include <bits/stdc++.h>
using namespace std;

// Pattern: level-order traversal for shortest steps in unweighted graph.
// Example: shortest path in grid with obstacles.
// Time: O(V + E) ; Space: O(V)
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return -1;
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        dist[0][0] = 1;
        q.push({ 0, 0 });
        int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (grid[nr][nc] == 1 || dist[nr][nc] != -1) continue;
                dist[nr][nc] = dist[r][c] + 1;
                q.push({ nr, nc });
            }
        }
        return dist[m - 1][n - 1];
    }
};
