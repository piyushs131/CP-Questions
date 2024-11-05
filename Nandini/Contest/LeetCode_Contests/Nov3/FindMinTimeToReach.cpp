#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) 
    {
        // Using a min-heap priority queue for {time, {pos}}
    priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
        pq.push({0, {0, 0}});
        
        long long drow[4] = {-1, 0, 1, 0}; 
        long long dcol[4] = {0, 1, 0, -1};
        long long row = moveTime.size();
        long long col = moveTime[0].size();
        long long ans = LLONG_MAX;

        vector<vector<long long>> check(row, vector<long long>(col, LLONG_MAX));
        check[0][0] = 0;
        
        while (!pq.empty()) 
        {
            long long time = pq.top().first;
            long long r = pq.top().second.first;
            long long c = pq.top().second.second;
            pq.pop();

            if (r == row - 1 && c == col - 1) 
            {
                ans = min(ans, time);
                continue;
            }
            
            for (long long i = 0; i < 4; i++) 
            {
                long long newr = r + drow[i];
                long long newc = c + dcol[i];

                if (newr >= 0 && newc >= 0 && newr < row && newc < col) 
                {
                    long long t = time + 1;

                    if (time < moveTime[newr][newc]) 
                        t += moveTime[newr][newc] - time;

                    if (check[newr][newc] <= t) continue;

                    check[newr][newc] = t;
                    pq.push({t, {newr, newc}});
                }
            }
        }
        return ans;
    }
};
