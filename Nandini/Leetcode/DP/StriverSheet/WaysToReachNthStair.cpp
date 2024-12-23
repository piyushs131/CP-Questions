#include <bits/stdc++.h> 
using namespace std;
int count(int n,vector<unsigned long int> &mem)
{
    if(n==1 || n==0)
    {
        mem[n]=n;
        return 1;
    }

    if(mem[n]!=-1)
    return mem[n];

    mem[n]=count(n-1,mem) + count(n-2,mem);
    return mem[n];
}
int countDistinctWays(int n) 
{
  vector<unsigned long int> mem(n+1,-1);
   return count(n,mem);
}
