#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    long long minNumberOfSeconds(int hgt, vector<int>& times) 
    {
       lli l = 0, u = 1e18;
       lli res = u;
       while (l < u) {
           lli mid = l + (u - l) / 2LL;
           lli ans = 0LL;

           for (int i = 0; i < times.size(); i++) {
               lli a = 1LL, b = (lli)(hgt);
               while (a <= b) {
                   lli m = a + (b - a) / 2LL;
                   lli temp = m * (m + 1LL) / 2LL;
                   
                   if (temp <= mid / times[i]) 
                       a = m + 1LL;
                   else 
                       b = m - 1LL;
               }
               ans += b;
           }

           if (ans >= (lli)(hgt)) {
               res = mid;
               u = mid; 
           } else {
               l = mid + 1LL;
           }
       }
       return res;
    }
};
