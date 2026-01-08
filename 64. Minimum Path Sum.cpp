#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = grid[i][j];
                }
                else {
                    int left = grid[i][j], up = grid[i][j];
                    j > 0 ? left += temp[j - 1] : left += 1e9;
                    i > 0 ? up += prev[j] : up += 1e9;
                    temp[j] = min(left, up);
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};