#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBalanced(string nums) 
    {
       int s1=0,s2=0,n = nums.size();
       for(int i=0 ; i<n ; i++) {
        if(i%2) s1+= nums[i]-'0';
        else s2+= nums[i]-'0';
       }
       return s1==s2;
    }
};