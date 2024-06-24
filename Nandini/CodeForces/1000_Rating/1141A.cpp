#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int count =0;
    if(m%n!=0)
    {
        cout << -1 ;
        return 0;
    }
    m = m/n;
    while(m%2==0)
    {
        m = m/2;
        count++;
    }
    while(m%3==0)
    {
        m = m/3;
        count++;
    }
    if(1==m) cout << count;
    else 
    cout << -1 ;
}
