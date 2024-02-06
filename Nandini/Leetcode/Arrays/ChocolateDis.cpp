// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
       int i;
       sort(a.begin(),a.end());
       long long diff;
       long long ans=INT_MAX;
       for(i=0 ; i<n ; i++)
       {
           if(i+m-1 < n)
           {
                diff = a[i+m-1] - a[i];
                ans = min(ans,diff);
           }
           else 
           break;
       }
       return ans;
    }
};
int main()
{
    Solution obj;
    vector<long long > a{1,5,6,2,4,8};
    long long n = 6, m = 4;
    cout << " ans = " << obj.findMinDiff(a,n,m);
}