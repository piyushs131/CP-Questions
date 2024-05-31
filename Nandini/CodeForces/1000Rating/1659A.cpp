#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r, b;
        cin >> n >> r >> b;
        int minR = r / (b + 1); 
        int extraR = r % (b + 1);

        string result;
        for (int i = 0; i < b; i++)
        {
            result += string(minR, 'R');
            if (extraR > 0)
            {
                result += 'R';
                extraR--;
            }
            result += 'B';
        }
        result += string(minR, 'R');
        if (extraR > 0)
        {
            result += string(extraR, 'R');
        }
        
        cout << result << endl;
    }
    return 0;
}
