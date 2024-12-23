#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back
#define pf push_front
#define ff first 
#define ss second
using namespace std;
int  main ()
{   
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
 
        pair<ll,ll> arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].ff;
            arr[i].ss=i;
        }
 
        sort(arr,arr+n);
 
        ll time=0;
        int ans[n];
        int idx=1;
        for(int i=n-1;i>=0;i-=2)
        {   
            ll temp = 2*idx;
            time= time + (arr[i].ff)*temp;
            ans[arr[i].ss]=idx;
 
            idx++;
        }
 
        idx=-1;
        for(int i=n-2;i>=0;i-=2)
        {
            int temp = 2*abs(idx);
            time = time  +  (arr[i].ff)*temp;
            ans[arr[i].ss]=idx;
 
            idx--;
        }
 
        cout<<time<<endl;
        cout<<0<<' ';
        for(int i=0;i<n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
 
    return 0;
}
