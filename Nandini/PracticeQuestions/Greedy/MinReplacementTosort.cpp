#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n = nums.size();
        int last = nums[n-1];
        
        for(int i=n-2 ; i>=0 ; i--){
            ans += nums[i] / last;
            
            if( nums[i] % last==0){
                ans--;
            }
            else{               
                int y = (nums[i] / last)+1 ;
                last = nums[i] / y;
            }
        }
        return ans;
    }
};