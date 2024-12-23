#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
      vector<int> change(n+1,0);
        for(auto it: queries)
            {
                int a = it[0];
                int b = it[1];

                change[a]--;
                if(b+1<n)
                change[b+1]++;
            }
        int diff =0;
        
        for(int i=0 ; i<n ;i ++) {
            diff+=change[i];
            nums[i]+=diff;
            if (nums[i] > 0) {
                return false; 
            }
        }
        return true;
    }
};