#include <bits/stdc++.h>
using namespace std;
#define lli long long int

void solve() 
{
    string s;
    cin >> s;
    string ans = "";
    int count =1;
    ans+=s[0];
    if(s.size()==1)
    {
        if(s[0]!='w')
        ans+='w';
        else 
        ans+='k';
        cout << ans << endl;
        return;
    }
    for(int i=1 ;i<s.size() ; i++)
    {
        if(s[i]!=s[i-1])
        ans+=s[i];

        else if(count==1 && s[i]==s[i-1])
        {
            count++;
            if(s[i]!='w')
            ans+='w';
            else 
            ans+='k';
            ans+=s[i];
        }
        else 
        {
            ans+=s[i];
        }
    }
    if(count==1)
    {
        if(ans[ans.size()-1]!='w')
            ans+='w';
            else 
            ans+='k';
    }
    cout << ans << endl;    
}

int main() 
{
   int t;
   cin >> t;
   while(t--)
   solve();
}
