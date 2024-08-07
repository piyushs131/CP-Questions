#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
   string s,t;
   cin >> s >> t;
   int i=0,j=0;
   while(i<s.size() && j<t.size())
   {
    if(s[i]==t[j])
    {
        i++,j++;
    }
    else if(s[i]=='?'){
        s[i] = t[j];
        i++;
        j++;
    }
    else i++;
   }
   if(i>=s.size() && j<t.size()){
    cout << "NO" << endl;
    
   }else {
    for(int i=0 ;i<s.size() ; i++)
    {
        if(s[i]=='?') s[i] ='a';
    }
    cout << "YES" << endl;
    cout << s << endl;
   }
}
int main() 
{
    int t;
    cin >> t;
    while(t--)
    solve();
}
