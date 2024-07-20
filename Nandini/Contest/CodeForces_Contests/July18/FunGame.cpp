#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  if (s[0] == '1')
  {
    cout << "YES" << endl;
    return;
  }
  int i = 0;
  while (s[i] != '1' && s[i] == t[i])
    i++;

  if(i>=n)
  cout << "YES" << endl;
  else if (s[i]=='1' )
  {
    cout << "YES" << endl;
  } 
  else
  {
    cout << "NO" << endl;
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
