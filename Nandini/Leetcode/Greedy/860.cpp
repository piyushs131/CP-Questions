#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        if(bills[0]!=5)return false;
       unordered_map<int,int> mp;
        int i,n = bills.size();
        for(i=0 ; i<n ; i++)
        {
            mp[bills[i]]++;
            if(bills[i]==10)
            {
                if(mp[5]!=0) {
                    mp[5] --;
                }
                else return false;
            }
            else if(bills[i]==20)
            {
                if(mp[10]!=0 && mp[5]!=0) {
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>2)
                {
                    mp[5]= mp[5]-3;
                }
                else return false;
            }
        }
        return true;
    }
};