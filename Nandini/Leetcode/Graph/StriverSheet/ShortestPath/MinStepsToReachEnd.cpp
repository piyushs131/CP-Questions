#include <bits/stdc++.h>
using namespace std;

int mod = 100000;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;
        
        vector<int> dist(mod, INT_MAX);
        queue<pair<int, int>> q; // (current_value, steps)
        
        dist[start] = 0;
        q.push({start, 0});
        
        while (!q.empty()) {
            int current = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            for (int num : arr) {
                int next = (current * num) % mod;
                if (steps + 1 < dist[next]) {
                    dist[next] = steps + 1;
                    if (next == end) return steps + 1;
                    q.push({next, steps + 1});
                }
            }
        }
        
        return -1;
    }
};
