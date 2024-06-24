#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
  int a,b,c;
  cin >> a >> b >> c;
  if(a==b)
  {
    int avg = a;
    cout << abs(a-avg) + abs(b-avg) + abs(c-avg) << endl;
    return;
  }
  else if(b==c)
  {
    int avg = b;
    cout << abs(a-avg) + abs(b-avg) + abs(c-avg) << endl;
    return;
  }
  else if(a==c)
  {
    int avg = a;
    cout << abs(a-avg) + abs(b-avg) + abs(c-avg) << endl;
    return;
  }
  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  sort(v.begin(),v.end());
  a = v[0],b=v[1],c=v[2];
  if(abs(a-b)<=5 && abs(b-c)<=5)
  {
    int avg = (a+b+c)/3;
    cout << abs(a-avg) + abs(b-avg) + abs(c-avg) << endl;
  }
  else 
  {
     if(b-a > c-b)
     {
        int avg = (b+c)/2;
        cout << abs(a-avg) + abs(b-avg) + abs(c-avg) << endl;
     }
     else 
     {
        int avg = (a+b)/2;
        cout << abs(a-avg) + abs(b-avg) + abs(c-avg) << endl;
     }
  }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}
