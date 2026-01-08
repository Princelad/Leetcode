#include <bits/stdc++.h>
using namespace std;

// Pattern: sort by end time, pick non-overlapping intervals greedily.
// Example: find max number of non-overlapping intervals.
// Time: O(n log n) ; Space: O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
            });
        int keep = 1;
        int end = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                ++keep;
                end = intervals[i][1];
            }
        }
        return static_cast<int>(intervals.size()) - keep; // removals
    }
};
