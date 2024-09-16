#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int odd = n/2, even = n/2;
    stack<pair<char,int>> st;
    int ans=0,num=1;
    for(int i=0 ;i <n ; i++)
    {
        if(s[i]=='(')
        st.push({s[i],num});
        else if(!st.empty() && st.top().first=='(' && s[i]=='_')
        {
            ans+=num-st.top().second;
            st.pop();
            s[i] = ')';
        }
        else if(!st.empty() && st.top().first=='_' && s[i]==')')
        {
            ans+=num-st.top().second;
            st.pop();
            s[i-1] = '(';
        }
        else if(s[i]=='_') {
            st.push({s[i],num});
        }
        num++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    // solve();
    return 0;
}
