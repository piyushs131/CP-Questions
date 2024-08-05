#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& ht) 
    {
      int n = ht.size();
      vector<int> suffix(n);
      vector<int> prefix(n);
      prefix[0] = ht[0];
      for(int i=1 ; i<n ; i++)
      {
        prefix[i] = max(prefix[i-1],ht[i]);
      }
      suffix[n-1] = ht[n-1];
      for(int i=n-2 ; i>=0 ; i--)
      {
        suffix[i] = max(suffix[i+1],ht[i]);
      }

      int ans =0;
      for(int i=1 ; i<n-1 ; i++)
      {
        ans+= min(prefix[i],suffix[i])-ht[i];
      }
      return ans;
    }
};

class Solution2 {
public:
    int trap(vector<int>& ht) 
    {
      int l=0,r=ht.size()-1,left =INT_MIN,right = INT_MIN;  
      int ans =0;
      while(l<r)
      {
        left = max(left,ht[l]);
        right = max(right,ht[r]);
        ans+= (left<right)? left-ht[l++]:right-ht[r--];
      }
      return ans;
    }
};