#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    int sum=a;
    int n = a;
    while(n>=b)
    {
        sum+= n/b;
        n = n/b + n%b;
    }
    cout << sum;
}