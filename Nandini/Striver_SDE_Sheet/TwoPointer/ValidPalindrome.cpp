#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) 
    {
       int n = s.size();
       int i=0,j=n-1;
       while(i<j)
       {
         if(!isalnum(s[i]))
         i++;
         else if(!isalnum(s[j]))
         j--;
         else if(tolower(s[i])==tolower(s[j]))
         {
            i++;
            j--;
         }
         else return false;
       }
       return true; 
    }
};