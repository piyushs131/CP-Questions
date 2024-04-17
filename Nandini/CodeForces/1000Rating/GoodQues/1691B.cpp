#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long long a[100005],b[100005];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=i+1;
		}
		int cnt=1,flag=0;
		for(int i=1;i<n;i++)
		{
			while(a[i]==a[i-1]&&i<n)
			{
				cnt++;
				swap(b[i],b[i-1]); 
				i++;
			 } 
			 if(cnt<=1)
			 {
			 	flag=1;
			 	break;
			 }
			 else
			 cnt=1; 
		}
		if(a[n-1]!=a[n-2])
		flag=1;
		if(flag==1)
		cout<<"-1";
		else
		for(int i=0;i<n;i++)
		cout<<b[i]<<" ";
		cout<<endl;
	}
 }