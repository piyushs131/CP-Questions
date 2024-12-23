#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	vector<int> nums;
	int i=1,j = n*n;

	// if n=3 then 1 9 2 8 3 7 4 6 5
	while(i<=j)
	{
		nums.push_back(i++);
		if(j>=i)nums.push_back(j--);
	}

	// printing nums from left to right and then right to left with n elements in a row
	for(int i=0 ;i <n ; i++){
		for(int j=0 ;j <n ; j++)
		 cout << nums[i*n+j] << " ";

		 cout << endl;
		 i++;
		 if(i<n){
			for(int j=0 ; j<n ; j++){
				cout << nums[(i+1)*n-j-1] << " ";
			}
			cout << endl;
		 }
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
