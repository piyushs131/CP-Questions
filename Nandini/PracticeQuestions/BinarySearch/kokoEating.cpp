#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long isPossible(vector<int> piles,long long hrs)
    {
        long long n = piles.size();
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += ceil((double)piles[i] / (double)hrs);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
       int n = piles.size();
       long long l=1,u=*max_element(piles.begin(),piles.end()), mid;
       while(l<=u)
       {
         mid = l+(u-l)/2;
         long long m = isPossible(piles,mid);
         if(m<=h) u = mid-1;
         else l = mid+1;
       }
       return l;
    }
};