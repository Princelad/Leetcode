#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = (int)height.size() - 1;
        int area = 0;

        while (left <= right) {
            area = max((right - left) * (min(height[left], height[right])), area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return area;
    }
};