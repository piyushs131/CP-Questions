#include<bits/stdc++.h>
using namespace std;
static bool cmp(pair<int,int> a,pair<int,int> b)
{
  return a.second<b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) 
{
   vector<pair<int,int> > v;
   pair<int,int> p;
   int i,n = start.size();
   for(i=0 ; i<n ;i ++)
   {
    p = make_pair(start[i],finish[i]);
    v.push_back(p);
   } 
   sort(v.begin(),v.end(),cmp);
   int num = v[0].second,count=1;
   for( i=1 ; i<n ;i ++)
   {
     if(v[i].first>=num)
     {
       count++;
       num = v[i].second;
     }
   }
   return count;
}