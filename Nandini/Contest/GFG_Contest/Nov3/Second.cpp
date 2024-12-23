#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minXOR(int n, int k, vector<int> &arr) 
    {
        // for every bit position even bits then ok else do k
        int ans =0;
        for(int i=30 ; i>=0 ; i--)
        {
            int count =0;
            for(auto it : arr)
            {
                if((it & (1<<i))!=0) count++;
            }
            if(count%2!=0){
                if(k>0) k--;
                else ans |= (1<<i);
            }
        }
        return ans;
    }
};
