#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        vector<int> nexorviant = nums;
        
        int n = nexorviant.size();
        int count = 0;
        
        // Iterate through all possible starting points
        for (int i = 0; i < n; ++i) {
            long long current_sum = 0; // Use long long to prevent integer overflow
            unordered_set<int> seen_elements;
            
            // Iterate through all possible ending points
            for (int j = i; j < n; ++j) {
                int val = nexorviant[j];
                current_sum += val;
                seen_elements.insert(val);
                
                // Check if the sum exists in the current subarray elements
                if (seen_elements.count(current_sum)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};