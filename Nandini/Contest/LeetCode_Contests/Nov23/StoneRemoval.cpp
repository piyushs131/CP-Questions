#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canAliceWin(int n) {
        int val = 10;
        bool flag = false;
        while(n!=0)
        {
            if(n<val) break;
            n-=val;
            val--;
            flag = !flag;
        }
        return flag?true:false;
    }
};