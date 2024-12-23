#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) 
    {
        // eg when n = 5
        // msb = 3(number of bits in 5) and 1<<msb is 8 
        // 8-1 = 7 ^ 5 = 2-> ans as 1 1 1 ^ 1 0 1 = 0 1 0 
        if(n==0) return 1;
        // most significant bit
        int msb = log2(n) + 1 ;
        return ((1<<msb)-1)^n;  
    }
};