#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kAndLessDiffInt(vector<int>& nums, int k) {
        int count = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        while (r < n) 
        {
            mp[nums[r]]++;
            while (mp.size() > k) 
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                mp.erase(nums[l]);

                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return kAndLessDiffInt(nums, k) - kAndLessDiffInt(nums, k - 1);
    }
};