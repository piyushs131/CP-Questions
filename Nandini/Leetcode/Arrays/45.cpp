#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) {
            return 0;
        }
        int max_1 = nums[0], k = min(len-1,nums[0]), count = 1;
        for(int i=1; i<=k; i++) {
            max_1 = max(nums[i]+i, max_1);
            if(i==k) {
                if(i==len-1) {
                    return count;
                }
                k = min(len-1, max_1);
                count++;
            }
        }
        return 0;
    }
};