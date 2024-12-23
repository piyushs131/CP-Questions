#include<bits/stdc++.h>
using namespace std;
int frogJump2(int n, vector<int> &heights,vector<int> &memo)
{
    if(n==0)
    {
        memo[n]=n;
        return n;
    }

    if(memo[n]!=-1)
    return memo[n];
    int fs = frogJump2(n-1,heights,memo) + abs(heights[n] - heights[n-1]);
    int ss = INT_MAX;
    if(n>1)
    {ss = frogJump2(n-2,heights,memo) + abs(heights[n] - heights[n-2]);}

    memo[n]=min(fs,ss);
    return memo[n];
}
int frogJump(int n,vector<int> heights)
{
    vector<int> memo(n,-1);
    return frogJump2(n-1,heights,memo);
}
