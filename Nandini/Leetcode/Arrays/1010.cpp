#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
       int i,n = time.size() ,sum =0 ;
        unordered_map<int,int> mp;
         for (int t : time) 
         {     
            int remainder = t % 60;
            int complement = (60 - remainder) % 60; 
            sum += mp[complement]; 
            mp[remainder]++;
        }
        return sum;
    }
};