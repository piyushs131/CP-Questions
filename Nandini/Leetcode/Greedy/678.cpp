#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) 
    {
       stack<int> left;
        stack<int> star;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i]=='(') left.push(i);
            else if(s[i]=='*')star.push(i);
            else 
            {
                if(!left.empty()) left.pop();
                else if(!star.empty())star.pop();
                else
                {
                    return false;
                }
            }
        }
        while(!left.empty() && !star.empty())
        {
            if(star.top()<left.top()) return false;
            else 
            {
                star.pop();
                left.pop();
            }
        }
        if(!left.empty()) return false;
        return true;
    }
};