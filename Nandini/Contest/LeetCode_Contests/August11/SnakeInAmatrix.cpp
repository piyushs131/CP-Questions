#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) 
    {
       int i=0,j=0;
       int num =0;
       for(auto it : commands)
       {
         if(it=="RIGHT")
         {
            if(j<n)
            {
                j++;
                num = i*n + j;
            }
         }
         else if(it=="DOWN")
         {
            if(i<n)
            {
                i++;
                num = i*n + j;
            }
         }
         else if(it=="UP")
         {
            if(i>0)
            {
                i--;
                num = i*n + j;
            }
         }
         else 
         {
            if(j>0)
            {
                j--;
                num = i*n + j;
            }
         }
       }
       return num; 
    }
};