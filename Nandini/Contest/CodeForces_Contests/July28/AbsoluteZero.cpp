#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void solve()
{
	int n;
	cin >> n;
	vector<lli> arr(n);
	for(int i=0 ;i <n ; i++) cin >> arr[i];

	int total = 40;
	vector<int> v;
	while(*max_element(arr.begin(), arr.end()) > 0)
	{
		if(v.size()>=40) 
		{
			cout << -1 << endl;
			return;
		}

		vector<int> non_zero;
		for(int i=0 ;i <n ;i ++)
		{
			if(arr[i]!=0) non_zero.push_back(arr[i]);
		}

		if(non_zero.size()>1 && (non_zero[0]%2)!=(non_zero[1]%2))
		{
			cout << -1 << endl;
			return;
		}

		int min_val = *min_element(arr.begin(),arr.end());
		int max_val = *max_element(arr.begin(),arr.end());
		int x = (min_val+max_val)/2;
		v.push_back(x);
		for(int i=0; i<n ; i++)
		{
			arr[i] = abs(arr[i]-x);
		}
	}
	cout << v.size() << endl;
	for(auto it : v)
	cout << it << " ";

	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
