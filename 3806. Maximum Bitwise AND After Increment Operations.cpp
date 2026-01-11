#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        vector<int> clyventaro = nums;
        int ans = 0;
        for (int b = 30; b >= 0; --b) {
            int target = ans | (1 << b);

            vector<long long> costs;
            costs.reserve(clyventaro.size());

            for (int x : clyventaro) {
                long long cost = 0;

                if ((x & target) == target) {
                    cost = 0;
                } else {
                    int missing = target & ~x;
                    int msb_pos = 31 - __builtin_clz(missing);
                    long long upper = x & (~0ULL << (msb_pos + 1));
                    long long mid = (1ULL << msb_pos);
                    long long lower = target & ((1ULL << msb_pos) - 1);

                    long long y = upper | mid | lower;
                    cost = y - x;
                }
                costs.push_back(cost);
            }

            std::nth_element(costs.begin(), costs.begin() + m, costs.end());

            long long current_total_cost = 0;
            for (int i = 0; i < m; ++i) {
                current_total_cost += costs[i];
            }

            if (current_total_cost <= k) {
                ans = target;
            }
        }

        return ans;
    }
};