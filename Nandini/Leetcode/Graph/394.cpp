#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) 
    {
      string ans="";
      stack<char> st;
      stack <string> st2;
      for(int i=0; i<s.size() ; i++)
      {
        if(s[i]>=48 && s[i]<=57 || s[i]>=97 && s[i]<=122) 
         st.push(s[i]);
      }  
      while(!st.empty())
      {
        char ch= st.top(); st.pop();
        string temp="";
         if(ch>=97 && ch<=122)
         {
            st2.push(string(1, ch));
         }
         else 
         {
            int n = ch -'0';
            cout << "n=" << n << endl;
            while(!st2.empty())
            {
              temp+=st2.top();
              st2.pop();
            }
            while(n--)
            {
                cout << "PUshing: " << temp << endl;
                st2.push(temp);
            }
         }
      }

      while(!st2.empty())
      {
        ans+=st2.top(); st2.pop();
      }
      return ans;
    }
};