#include<bits/stdc++.h>
using namespace std;
bool isnotDivisible(vector<int> &v,int num)
{
  int n = v.size();
  for(int i=1; i<n ; i++)
  {
    if(v[i]%num!=0)
    return true;
  }
  return false;
}
int main()
{
  int T;
  cin >> T;
  int mini ,n,k;
  vector<int> v;
  while(T--)
  {
    mini = INT_MAX;
    cin >> n;
    for(int i=0 ; i<n ; i++)
    {
      cin >> k;
      v.push_back(k);
      if(mini>n)
      mini = n;
    }

    sort(v.begin(),v.end());
    if(v[0]!=v[1])
    cout << "YES\n";
    else
    {
       if(isnotDivisible(v,v[0]))
       {
         cout << "YES\n";
       }
       else 
       cout << "NO\n";
    }

    v.clear();
  }
}