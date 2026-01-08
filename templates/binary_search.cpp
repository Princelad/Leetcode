#include <bits/stdc++.h>
using namespace std;

// Pattern: binary search on answer (monotonic predicate) or index.
// Example: find minimum capacity to ship packages within days.
// Time: O(n log M) where M is search space ; Space: O(1)
class Solution {
public:
    int shipWithinDays(const vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        auto canShip = [&](int cap) {
            int d = 1, load = 0;
            for (int w : weights) {
                if (load + w > cap) { ++d; load = 0; }
                load += w;
            }
            return d <= days;
            };
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canShip(mid)) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
