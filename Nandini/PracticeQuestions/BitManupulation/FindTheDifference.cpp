#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) 
    {
       char xorr = 0;
       for(int i=0 ;i <t.size() ;i ++)
       {
        xorr = xorr^t[i];
        xorr = xorr^s[i];
       } 
       return xorr;
    }
};