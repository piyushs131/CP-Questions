#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
       int ans =0,lb=0,ub= height.size()-1;
       while(lb<=ub)
       {
         int area = min(height[lb],height[ub]) * abs(ub-lb);
         ans = max(ans,area);
         if(height[lb] < height[ub])
         lb++;
         
         else ub--;
       }
       return ans; 
    }
};