#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
       string str=".";
       stack<string> st;
       for(int i=0 ; i<S.size() ; i++)
       {
           if(S[i]=='.')
           {
               st.push(str);
               str="";
           }
           str+=S[i];
       }
       while(!st.empty())
       {
           str+=st.top();
           st.pop();
       }
       str.erase(str.begin()+0);
       return str;
    } 
};