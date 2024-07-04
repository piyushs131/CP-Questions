#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp(vector<int>& boxes, vector<vector<vector<int>>>& memo, int l, int r, int k) {
        if (l > r) return 0;
        if (memo[l][r][k] != -1) return memo[l][r][k];
        
        // Option 1: Remove the last k boxes of boxes[r] directly
        int res = (k + 1) * (k + 1) + dp(boxes, memo, l, r - 1, 0);
        
        // Option 2: Try to merge boxes[r] with some previous box of the same color
        for (int i = l; i < r; ++i) {
            if (boxes[i] == boxes[r]) {
                res = max(res, dp(boxes, memo, l, i, k + 1) + dp(boxes, memo, i + 1, r - 1, 0));
            }
        }
        
        memo[l][r][k] = res;
        return res;
    }
    
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return dp(boxes, memo, 0, n - 1, 0);
    }
};
