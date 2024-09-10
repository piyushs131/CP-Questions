#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        if(dividend==divisor) return 1;
       bool flag = true;
       if(dividend<0 && divisor>0) flag = false; 
       if(dividend>0 && divisor<0) flag = false;

       long n = abs(dividend), d = abs(divisor),ans=0;
       while(n>=d)
       {
         int count =0;
         while(n>= (d<< (count+1)))count++;

         ans+=(1<<count);
         n-= (d<<count);
       }

       if(ans==(1<<31) && flag==false)return INT_MIN;
       if(ans==(1<<31) && flag) return INT_MAX;

       return flag?ans:-ans;
    }
};