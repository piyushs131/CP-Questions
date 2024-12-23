#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &ht)
    {
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
        int n = ht.size(), m = ht[0].size();
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        vector<vector<int>> v(n, vector<int>(m, 1e9));
        v[0][0] = 0;
        pq.push({{0, 0}, 0});
        int diff;
        while (!pq.empty())
        {
            int i = pq.top().first.first;
            int j = pq.top().first.second;
            diff = pq.top().second;
            pq.pop();

            if(i==n-1 && j==m-1) return diff;
            for (int k = 0; k < 4; k++)
            {
                int r = i + drow[k];
                int c = j + dcol[k];
                if (r >= 0 && c >= 0 && r < n && c < m)
                {
                    int newEffort =  max(diff, abs(ht[i][j] - ht[r][c]));
                    if(newEffort<v[r][c])
                    {
                       v[r][c] = newEffort;
                       pq.push({{r, c}, v[r][c]});
                    }
                    
                }
            }
        }
        return v[n - 1][m - 1];
    }
};