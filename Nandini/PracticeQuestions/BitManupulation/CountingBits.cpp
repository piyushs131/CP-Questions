#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans;
        int count =0;
       for(int i=0 ;i <=n ; i++)
       {
          ans.push_back(__builtin_popcount(i));
       } 
       return ans;
    }
};