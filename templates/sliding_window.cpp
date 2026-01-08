#include <bits/stdc++.h>
using namespace std;

// Pattern: expand right, shrink left while maintaining a condition.
// Example: longest subarray with at most k distinct characters.
// Time: O(n) ; Space: O(k)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(const string& s, int k) {
        unordered_map<char, int> freq;
        int best = 0;
        for (int l = 0, r = 0; r < static_cast<int>(s.size()); ++r) {
            ++freq[s[r]];
            while (static_cast<int>(freq.size()) > k) {
                if (--freq[s[l]] == 0) freq.erase(s[l]);
                ++l;
            }
            best = max(best, r - l + 1);
        }
        return best;
    }
};
