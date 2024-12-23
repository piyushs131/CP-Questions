#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n,k;
	cin >> n >> k;

    vector<vector<int> > v(n,vector<int>(n,0));
	for(int i=0 ;i <n ; i++)
	{
		string c;
		cin >> c;
		int j=0;
		for(int h=0 ; h<c.size() ; h++)
		v[i][j++] = c[h]-'0';


	}
    int i=0;
	while(i<n)
	{
        int j=0; 
		while(j<n)
		{
			cout << v[i][j] ;
			j+=k;
		}
		cout << endl;
		i+=k;
	}

}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
