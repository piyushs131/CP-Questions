#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maxScoreUtil(vector<int>& a, vector<int>& b, int ind1, int ind2, vector<vector<long long>>& dp) 
    {
        if (ind1 == 4) 
            return 0;
        if (ind2 >= b.size()) 
            return LLONG_MIN / 2; 
        
        if (dp[ind1][ind2] != -1) 
            return dp[ind1][ind2];
        
        long long pick = (ind2 < b.size() ? (long long)a[ind1] * b[ind2] + maxScoreUtil(a, b, ind1 + 1, ind2 + 1, dp) : LLONG_MIN / 2);
        
        long long notPick = maxScoreUtil(a, b, ind1, ind2 + 1, dp);
        
        dp[ind1][ind2] = max(pick, notPick);

        return dp[ind1][ind2];
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> dp(5, vector<long long>(b.size() + 1, -1));
        return maxScoreUtil(a, b, 0, 0, dp);
    }
};
