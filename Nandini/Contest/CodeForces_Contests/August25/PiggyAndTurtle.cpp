#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector<int>
void solve()
{
	int n;
    cin >> n;
	vector<int> arr(n);
	for(int i=0 ; i<n ; i++) cin >> arr[i];

	sort(arr.begin(),arr.end());
	cout << arr[n/2] << endl;
	
}

int main() {
	int t; 
    cin >> t;
	while(t--) solve();
}

