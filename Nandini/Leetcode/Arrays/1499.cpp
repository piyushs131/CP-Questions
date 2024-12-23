#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
    {
        int ans = INT_MIN;
        deque<pair<int, int>> dq;
        
        for (const auto& point : points) 
        {
            int x = point[0], y = point[1];
            while (!dq.empty() && x - dq.front().second > k)
                dq.pop_front();
            
            if (!dq.empty())
                ans = max(ans, dq.front().first + y + x);
            
            while (!dq.empty() && dq.back().first <= y - x)
                dq.pop_back();
            
            dq.push_back({y - x, x});
        }
        
        return ans;
    }
};
