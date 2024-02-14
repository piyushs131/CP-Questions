#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCheck(string str,int st,string need)
    {
        int i;
        for(i=0 ; i<need.size() ;i ++)
        {
            if(str[st]!=need[i])
            {
                return false;
            }
            st++;
        }
        return true;
    }
    int strStr(string str, string needle) 
    {
        int i,n = str.size();
        for(i=0 ; i<n; i++)
        {
            if(str[i] == needle[0])
            {
                if(isCheck(str,i,needle))
                    return i;
            }
        }
        return -1;
    }
};