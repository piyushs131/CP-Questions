#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) 
    {
      int bits = 1;
      int num = n;
      num = num/2;
      while(num>0)
      {
        bits++;
        num /=2;
      }  
      for(int i=0 ; i<bits ; i++)
      {
         n = n^(1<<i);
      }
      return n;
    }
};