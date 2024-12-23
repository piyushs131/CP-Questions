#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n; 
    int ans = 0;

    if (n.length() > 1) 
    {
        while (n.length() > 1) 
        {
            int sum = 0;
            for (char digit : n) {
                sum += digit - '0'; 
            }
            n = to_string(sum); 
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
