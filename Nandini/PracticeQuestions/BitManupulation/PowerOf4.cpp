#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) 
    {
       if(n<=0) return false;
       // not power of 2
       if(n&(n-1)) return false;
       // the position of that 1 set bit should be even
       int size = log2(n);
       if(size%2==0) return true;

       return false;
    }
};