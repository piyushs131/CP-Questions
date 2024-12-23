#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector<int>
void solve()
{
	int n;
    cin >> n;
	string s;
	cin >> s;
	if(s[0] == s[n - 1]) cout << "No"<< endl;
    else cout << "Yes"<< endl;
}

int main() {
	int t; 
    cin >> t;
	while(t--) solve();
}

