#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> stringSequence(string target) 
    {
       vector<string> v;
       string str="";
       for(int i=0 ;i <target.size() ; i++)
       {
         char c= target[i];
         char s = 'a';
         str+=s;
         v.push_back(str);
         while(s!=c)
         {
            s+=1;
            // cout << "S=" << s << endl;
            str[i]= s;
            v.push_back(str);
         }
       } 
       return v;
    }
};