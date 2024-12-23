#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        map<int, int> mp;
        map<int, int> secret_mp;
        for(int i = 0; i < trust.size(); i++) 
        {
            mp[trust[i][0]]++;
            secret_mp[trust[i][1]]++;
        }   

        for(int i = 1; i <= n; i++) {
            if(mp[i] == 0 && secret_mp[i] == n - 1)
                return i;
        }

        return -1;
    }
};
