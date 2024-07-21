#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertBinary(int num)
    {
    bitset<32> bits(num);
    string binaryString = bits.to_string();
    size_t firstOne = binaryString.find('1');
    if (firstOne != string::npos) 
    {
       return binaryString.substr(firstOne);
    } else 
    {
        return "0";
    }

    }
    int minChanges(int n, int k) 
    {
       string a = convertBinary(n);
       string b = convertBinary(k);
       if(a==b) return 0;
       int ans =0;
       if(a.size()>b.size())
       {
          int diff = a.size()-b.size();
          string d = "";
          while(diff--)
          d+='0';

          for(int i=0 ; i<b.size() ;i ++)
          d+=b[i];

          b = d;
       }
       else if(a.size()<b.size()) return -1;

       for(int i=0 ; i<a.size() ; i++) 
       {
         if(b[i]=='0' && a[i]=='1') ans++;
         if(b[i]=='1' && a[i]=='0') return -1;
       }

       return ans;
    }
};