#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s;
    cin >> s;
    int count =0;
    int n= s.size();
    for(int i=0 ;i <n/2 ; i++)
    {
        if(s[i]!=s[n-i-1])
        count++;
    }
    if(count==1 || (count==0 && n%2!=0)) 
    {
        cout << "YES";
    }
    else cout << "NO";
}

int main()
{
    solve();
    return 0;
}
