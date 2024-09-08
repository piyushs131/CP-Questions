#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toBinary(int n) {
    string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    return binary;
    }
    string convertDateToBinary(string date) 
    {
        string ans = "";
        string s="";
       for(int i=0 ; i<date.size() ; i++)
       {
         if(date[i]=='-')
         {
           ans+=toBinary(stoi(s));
           ans+='-';
           s = "";
         }
         else s+=date[i];
       } 
       ans+=toBinary(stoi(s));
       return ans;
    }
};