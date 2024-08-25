#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) 
    {
        priority_queue<int, vector<int>, greater<int>> pq1; 
        priority_queue<int, vector<int>, greater<int>> pq2;

        int n = costs.size();
        int i = 0, j = n - 1;

        for (int idx = 0; idx < cand && idx < n; ++idx) {
            pq1.push(costs[i++]);
        }

        for (int idx = 0; idx < cand && j >= i; ++idx) {
            pq2.push(costs[j--]);
        }

        long long ans = 0;

        while (k--) 
        {
            int tp;
            if (pq1.empty() || (!pq2.empty() && pq2.top() < pq1.top())) 
            {
                tp = pq2.top();
                pq2.pop();
                if (j >= i) pq2.push(costs[j--]);
            } 
            else 
            {
                tp = pq1.top();
                pq1.pop();
                if (i <= j) pq1.push(costs[i++]);
            }
            ans += tp;
        }

        return ans;
    }
};
