#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0,t;
    cin >> n;
    for(int i=0 ;i <n ; i++)
    {
        cin >> t;
        sum+=t ;
    }
    n++;
    int position = sum%n;
    int count =0;
    for(int i=1 ; i<=5 ; i++)
    {
        position++;
        if(position>n)
        position=1;
        else if(position!=1) count++;
    }
    cout << count;
}