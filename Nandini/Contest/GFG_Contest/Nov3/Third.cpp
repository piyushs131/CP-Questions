#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int isPossible(int n, vector<int> &arr) 
    {
        vector<int> pref(n,0);
        vector<int> post(n,0);
        int t=0,f=0;
        for(int i=0 ;i <n ; i++)
        {
            int x = arr[i];
            while(x%2==0){
                t++;
                x/=2;
            }
            while(x%5==0){
                f++;
                x/=5;
            }
            
            pref[i] = min(t,f);
        }
        
        t=0,f=0;
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(arr[i]%2==0){
                t++;
                arr[i]/=2;
            }
            while(arr[i]%5==0){
                f++;
                arr[i]/=5;
            }
            
            post[i] = min(t,f);
        }
        
        for(int i=0 ; i<n-1 ; i++)
        {
            if(pref[i]==post[i+1]) return true;
        }
        return false;
    }
};