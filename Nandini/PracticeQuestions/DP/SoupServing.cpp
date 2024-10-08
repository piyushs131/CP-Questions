#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double solve(int a, int b, vector<vector<double>> dp) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if(dp[a][b] != -1.0){
            return dp[a][b];
        }
        return dp[a][b] = 0.25 * (solve(a - 100, b, dp) + solve(a - 75, b - 25, dp) + solve(a - 50, b - 50, dp) + solve(a - 25, b - 75, dp));
    }
    double soupServings(int n) {
        if(n >= 5000){
            return 1.0;
        }
        // n = (n+24) / 25;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1.0));
        return solve(n, n, dp);
    }
};