#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> arr)
{
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
                if (arr[i] > maxi)
                        maxi = arr[i];
        }
        return maxi;
}
int main()
{
        vector<int> arr{4, 6, 8, 2, 13, 6};
        cout << "max element " << fun(arr);
}