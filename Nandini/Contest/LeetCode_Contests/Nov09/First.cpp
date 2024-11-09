#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     bool pdt(int n,int t)
    {
       int val = 1;
        // cout << "N=" << n << endl;
        while(n)
            {
                val *= n%10;
                n = n/10;
            }
        return val%t==0?true:false;
    }
    int smallestNumber(int n, int t) 
    {
        while(true)
            {
                if(pdt(n,t)) return n;
                n++;
            }
        return 0;
    }
};