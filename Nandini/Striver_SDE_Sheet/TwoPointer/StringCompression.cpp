#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) 
    {
       int ind =0,i=0;
       int n = chars.size();
       while(ind<n) 
       {
          char ch = chars[ind];
          int count =0;
          while(ind<n && chars[ind]==ch)
          {
            ind++;
            count++;
          }
          chars[i++] = ch;

          if (count > 1) 
           {
                string countStr = to_string(count);
                for (char c : countStr) 
                {
                    chars[i++] = c;
                }
            }

       }
       return i;
    }
};