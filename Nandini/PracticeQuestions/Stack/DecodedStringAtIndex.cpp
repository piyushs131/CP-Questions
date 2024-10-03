#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeAtIndex(string s, int k) 
    {
       long long size = 0;
       for(auto it : s)
       {
         if(isalpha(it)) size++;
         else size = size*(it-'0');
       } 

       int n =s.size(),i;
       for(i=n-1 ; i>=0 ; i--)
       {
         k = k%size; // Modulo to keep k within the current size
         if(k==0 && isalpha(s[i])) return string(1,s[i]);
         if(isdigit(s[i]))
         {
            size = size/ (s[i]-'0');
         }
         else size--;
       }
       return "";
    }
};