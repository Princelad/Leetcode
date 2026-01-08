#include <bits/stdc++.h>
using namespace std;

// Pattern: greedy with heap to pick next best candidate.
// Example: schedule tasks with limited time -> select by smallest duration after sorting by deadline.
// Time: O(n log n) ; Space: O(n)
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
        priority_queue<int> maxHeap; // store durations
        int time = 0;
        for (auto& c : courses) {
            int dur = c[0], end = c[1];
            time += dur;
            maxHeap.push(dur);
            if (time > end) { time -= maxHeap.top(); maxHeap.pop(); }
        }
        return static_cast<int>(maxHeap.size());
    }
};
