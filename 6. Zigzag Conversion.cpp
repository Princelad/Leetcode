#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;  // no zigzag needed

        vector<string> rows(numRows, "");
        int r = 0, dir = 1;  // dir: +1 going down, -1 going up

        for (char c : s) {
            rows[r].push_back(c);
            if (r == 0) dir = 1;                   // bounce at top
            else if (r == numRows - 1) dir = -1;   // bounce at bottom
            r += dir;
        }

        // stitch rows together
        string ans;
        for (auto& row : rows) ans += row;
        return ans;
    }
};