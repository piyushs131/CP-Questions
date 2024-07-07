#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1)
            return ans;

        ans.push_back({1, 1});
        
        numRows -= 2;
        while (numRows--) 
        {
            vector<int> v;
            int n = ans.size()-1;
            for (int i = 0; i < n+1; i++) {
                if (i - 1 < 0)
                    v.push_back(1);
                else 
                    v.push_back(ans[n][i] + ans[n][i - 1]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};