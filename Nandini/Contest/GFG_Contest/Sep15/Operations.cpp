#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long minOps(long long a, long long b) 
    {
        if(b<a) return -1;
        if(b==a) return 0;
        
        long long steps = 0;
       while(a!=b)
       {
           long long x = floor(sqrtl(b));
           long long y = x*x;
           if(a==b) return steps;
           if(x<a)
           {
               steps += b-a;
               b = a;
           }
           else {
               steps+= b-y;
               b = y;
               if(b!=a)
               {
                   steps++;
                   b = x;
               }
           }
       }
       return steps;
    }
};
