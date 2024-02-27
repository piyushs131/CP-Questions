#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int> > v;
        int i;
        for( i=0 ;i <n ; i++)
        {
            pair<int,int> p = make_pair(start[i],end[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        int count = 1,check = v[0].second;
        for( i=1 ; i<n ; i++)
        {
            if(v[i].first > check)
            {
              count++;
              check = v[i].second;
            }
        }
        return count;
    }
};