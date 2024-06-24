#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k,count =0,j,val=n;
        bool flag=0;
        cin >> n >> k;
        val =n;
        vector<int> v(n);
        for(int i=0 ; i<n ; i++)
            cin >> v[i];
        
        if(v[0]==v[n-1])
        {
            for(j=0 ; j<n ; j++)
            {
                if(v[0]==v[j])
                count++;

                if(count==k)
                break;
            }
            if(count==k)
            cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else 
        {
            for(j=0 ; j<n ; j++)
            {
                if(v[0]==v[j])
                count++;
                if(count==k)
                {
                    val = j;
                    count =0;
                    break;
                }
            }
            for(j=val+1 ; j<n ; j++)
            {
                if(v[j]==v[n-1])
                count++;
                if(count==k)
                {
                    flag =1;
                    break;
                }
            }

            if(flag==1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}