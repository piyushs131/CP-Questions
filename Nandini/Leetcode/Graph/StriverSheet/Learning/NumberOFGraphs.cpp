#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long count(int n) 
    {
        long long ans = pow(2,n*(n-1)/2);
        return ans;
    }
};