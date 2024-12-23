#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ispal(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
       int n = s.size();
       int l=0,r=n-1,count=1; 
       while(l<r)
       {
        // cout << "l=" << l << ",r=" << r << endl;
        if(s[l]==s[r]) {
            l++;
            r--;
        }
        else if(count!=0)
        { 
           if(ispal(s,l+1,r)) l++;
           else if(ispal(s,l,r-1)) r--;  
           else return false;
        //    cout << "l=" << l << ",r=" << r << endl;
           count--;
        }
        else return false;
       } 
       return true;
    } 
};