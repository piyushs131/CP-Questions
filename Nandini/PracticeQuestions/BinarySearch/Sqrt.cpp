#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) 
    {
       if(x==0 || x==1) return x;
       int l =1 , u = x;
       long long mid =x,ans=0;
       while(l<=u)
       {
        mid = l+ (u-l)/2;
        if(mid*mid==x) return mid;
        else if(mid*mid>x) u = mid-1;
        else {
            ans = mid;
            l = mid+1;
        }
       } 
       return ans;
    }
};