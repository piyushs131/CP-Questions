#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0; 

        unordered_map<int, int> mp;
        for (auto num : nums) mp[num]++;

        int ans = 0;
        for (auto& [num, count] : mp) 
        {
            if (k == 0) {
                if (count > 1) ans++;
            } else {
                if (mp.find(num + k) != mp.end()) ans++;
            }
        }

        return ans;
    }
};
