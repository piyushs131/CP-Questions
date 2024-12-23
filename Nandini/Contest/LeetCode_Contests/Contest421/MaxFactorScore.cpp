#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll gcd(ll a,ll b){
        if(b==0) return a;
        return gcd(b,a%b);
    }

    ll lcm(ll a,ll b)
    {
        return a*b/gcd(a,b);
    }
    long long maxScore(vector<int>& nums) 
    {
        ll n = nums.size();
        ll ans = INT_MIN;
        for(ll i=0 ; i<=n ; i++)
        {
            ll gcdd=0,lcmm=1;
            for(ll j=0 ;j <n ; j++)
            {
               if(i!=j)
               {
                 gcdd = gcd(nums[j],gcdd);
                 lcmm = lcm(nums[j],lcmm);
               }
            }
            ans = max(ans,gcdd*lcmm);
        }
        return ans;
    }
};