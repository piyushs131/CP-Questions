#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void bitManipulation(int num, int i) 
    {
        // Correctly check the ith bit
        i--;
        if ((num & (1 << i)) != 0) 
            cout << 1 << " ";
        else 
            cout << 0 << " ";
        
        // Correctly set the ith bit
        int setVal = num | (1 << i);
        cout << setVal << " ";
        
        // Correctly unset the ith bit
        int unsetVal = num & ~(1 << i);
        cout << unsetVal;
    }
};