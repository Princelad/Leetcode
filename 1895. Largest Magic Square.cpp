#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row_prefix(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_prefix[i][j + 1] = row_prefix[i][j] + grid[i][j];
            }
        }

        vector<vector<int>> col_prefix(m + 1, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                col_prefix[i + 1][j] = col_prefix[i][j] + grid[i][j];
            }
        }

        int maxSize = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = min(m - i, n - j) - 1; k > maxSize - 1; --k) {
                    int r2 = i + k;
                    int c2 = j + k;
                    long long targetSum = row_prefix[i][c2 + 1] - row_prefix[i][j];
                    bool isMagic = true;

                    for (int r = i; r <= r2; ++r) {
                        if (row_prefix[r][c2 + 1] - row_prefix[r][j] != targetSum) {
                            isMagic = false;
                            break;
                        }
                    }
                    if (!isMagic) continue;

                    for (int c = j; c <= c2; ++c) {
                        if (col_prefix[r2 + 1][c] - col_prefix[i][c] != targetSum) {
                            isMagic = false;
                            break;
                        }
                    }
                    if (!isMagic) continue;

                    long long diag1 = 0, diag2 = 0;
                    for (int d = 0; d <= k; ++d) {
                        diag1 += grid[i + d][j + d];
                        diag2 += grid[i + d][c2 - d];
                    }

                    if (diag1 == targetSum && diag2 == targetSum) {
                        maxSize = k + 1;
                        break;
                    }
                }
            }
        }
        return maxSize;
    }
};