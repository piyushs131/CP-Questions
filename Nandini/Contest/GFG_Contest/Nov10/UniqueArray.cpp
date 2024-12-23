#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int uniqueArray(int n, vector<int> &arr) {
        // we will find the unique array then n-array= remove this for unique
        unordered_map<int,int> mp;
        int i=0 ;
        for(; i<n ; i++) {
            if(mp[arr[i]]) break;
            mp[arr[i]]++;
        }
        i--;
        
        int j=n-1;
        for(; j>=0 ; j--)
        {
            if(mp[arr[j]]) break;
            mp[arr[j]]++;
        }
        j++;
        
        int ans = i+1 + n-j ; // starting me i tk ke unique + last me j tk ke unique
        j--;
        for(; j>=0 ; j--)
        {
            mp[arr[j]]++;
            while(i>=0 && mp[arr[j]]>1){
                mp[arr[i--]]--;
            }
            if(mp[arr[j]]==1) ans = max(ans,i+1+n-j);
            else break;
        }
        return n-ans;
    }
};