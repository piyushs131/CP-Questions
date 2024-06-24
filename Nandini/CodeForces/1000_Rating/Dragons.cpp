#include <bits/stdc++.h>
using namespace std;
#define ll long long
int op(pair<int,int> &a,pair<int,int> &b)
{
    return a.second>b.second;
}
int main()
{
    int s,n,a,b;
    cin >> s >> n;
    vector<pair<int,int> > p(n);
    for(int i=0 ; i<n ; i++)
    {
        cin >> a >> b;
        p[i].first = a,p[i].second = b;
    }
    sort(p.begin(),p.end(),op);
    int i;
    for( i=0 ; i<p.size() ; i++)
    {
        if(s>p[i].first)
        {
           s+= p[i].second;
           p.erase(p.begin()+i);
           i=-1;
        }
    }
    if(p.size()==0) cout << "YES" ;
    else 
    cout << "NO";
}