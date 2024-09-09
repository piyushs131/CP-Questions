#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string oddEven(int n) 
    {
        if(n&1==1) return "odd";
        return "even";
    }
};
