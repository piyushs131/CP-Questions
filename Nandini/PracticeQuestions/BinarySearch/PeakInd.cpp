#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
       int lb=0,ub = arr.size()-1,mid;
       int n = arr.size();
       while(lb<=ub)
       {
         mid = (lb+ub)/2;
         if((mid-1<0 || arr[mid]>arr[mid-1]) && (mid+1>=n || arr[mid]>arr[mid+1]))
         return mid;
         else if(mid+1<n && arr[mid+1]>arr[mid]) lb = mid+1;
         else ub = mid-1;
       }
       return mid;
    }
};