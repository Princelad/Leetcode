#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double min_y = 2e9;
        double max_y = -2e9;
        double total_area = 0;

        // 1. Calculate Search Bounds and Total Area
        for (const auto& sq : squares) {
            double y = sq[1];
            double l = sq[2];
            min_y = min(min_y, y);
            max_y = max(max_y, y + l);
            // Use double to prevent overflow for large areas
            total_area += (double)l * l;
        }

        double target = total_area / 2.0;
        double low = min_y;
        double high = max_y;

        // 2. Binary Search
        // 100 iterations provide precision far exceeding 10^-5
        for (int i = 0; i < 100; ++i) {
            double mid = low + (high - low) / 2.0;
            double area_below = 0;

            for (const auto& sq : squares) {
                double y = sq[1];
                double l = sq[2];

                // Check if the current square is strictly above the line
                if (mid <= y) continue;

                // Calculate the height of the square falling below the line 'mid'
                // It is capped at 'l' if the line is completely above the square
                double height_below = min((double)l, mid - y);
                area_below += height_below * l;
            }

            if (area_below < target) {
                low = mid;
            }
            else {
                high = mid;
            }
        }

        return high;
    }
};