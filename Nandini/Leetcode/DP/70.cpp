#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int climbStairs(int n) 
    {   
        vector<unsigned int> mem(n+1,-1);
        return climb(n,mem);
    }
    int climb(int n,vector<unsigned int> &mem)
    {
      if(n==0 || n==1)
        {
          mem[n]=n;
          return 1;
        }
        
        if(mem[n]!=-1)
        return mem[n];

        mem[n]=climb(n-1,mem) + climb(n-2,mem);
     
        return mem[n];
    }
};