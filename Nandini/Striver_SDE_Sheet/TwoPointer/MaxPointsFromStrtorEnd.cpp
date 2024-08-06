#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& card, int k) 
    {
        int n = card.size();
        int lmax =0,rmax=0;
        for(int i=0 ; i<k ; i++)
        lmax+=card[i];

        int ans =lmax;
        int l = k-1;
        int r = n-1;
        while(l>=0)
        {
            lmax-=card[l--];
            rmax+=card[r];
            r--;
            ans = max(ans,lmax+rmax);
        }
        return ans;
    }
};