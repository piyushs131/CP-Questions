#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        
        for (int i = 0; i < n; ++i) {
            v[i] = {nums[i], cost[i]};
        }
        
        sort(v.begin(), v.end());
        
        // Prefix sums of costs
        vector<long long> prefixSum(n);
        prefixSum[0] = v[0].second;
        
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + v[i].second;
        }
        
        // Calculate initial cost to make all elements equal to v[0].first
        long long totalCost = 0;
        for (int i = 1; i < n; ++i) {
            totalCost += (long long)(v[i].first - v[0].first) * v[i].second;
        }
        
        long long minCost = totalCost;
        
        for (int i = 1; i < n; ++i) {
            long long gap = v[i].first - v[i - 1].first;
            totalCost += prefixSum[i - 1] * gap;
            totalCost -= (prefixSum[n - 1] - prefixSum[i - 1]) * gap;
            minCost = min(minCost, totalCost);
        }
        
        return minCost;
    }
};
