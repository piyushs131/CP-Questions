#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
       int n = haystack.size();
       int m = needle.size();
       for(int i=0 ;i <n ; i++)
       {
         if(haystack[i]==needle[0])
         {
            int j=0;
            int ind = i;
            while(j<m && haystack[i]==needle[j])
            {
                j++;
                i++;
            }
            if(j==m) return ind;
            else i = ind;
         }
       }
       return -1;
    }
};