#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding window with last seen index for each ASCII char
        vector<int> last(256, -1);
        int best = 0;
        int left = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = s[right];
            if (last[c] >= left) {
                left = last[c] + 1; // move left past the previous occurrence
            }
            last[c] = right;
            best = max(best, right - left + 1);
        }

        return best;
    }
};