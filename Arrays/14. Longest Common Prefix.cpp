#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        if (strs.empty()) return res;

        // Find the minimum length among all strings
        int minLen = strs[0].length();
        for (const auto& s : strs) {
            minLen = min(minLen, (int)s.length());
        }

        // Vertical scanning: compare characters at same position across all strings
        for (int i = 0; i < minLen; i++) {
            char ch = strs[0][i];

            // Check if all strings have the same character at position i
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != ch) {
                    return res;  // Mismatch found, return current prefix
                }
            }

            // All strings have the same character at position i
            res += ch;
        }

        return res;
    }
};