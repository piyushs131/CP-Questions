#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int> maxReach(n + 1, 0);
        
        // Calculate the maximum right reach for each tap
        for (int i = 0; i <= n; ++i) 
        {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            maxReach[left] = max(maxReach[left], right);
        }
        
        int taps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        for (int i = 0; i <= n; ++i) 
        {
            if (i > farthest) 
            {
                // If the current position is beyond the farthest reach, return -1
                return -1;
            }
            farthest = max(farthest, maxReach[i]);
            if (i == currentEnd) 
            {
                // When we reach the current end, we need to use another tap
                taps++;
                currentEnd = farthest;
            }
            if (currentEnd >= n) 
            {
                // If the current end reaches or exceeds n, return the number of taps
                return taps;
            }
        }
        
        return -1;
    }
};
