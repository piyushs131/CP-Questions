#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int XORupto(int n) {
    if (n % 4 == 0) {
        return n;
    } else if (n % 4 == 1) {
        return 1;
    } else if (n % 4 == 2) {
        return n + 1;
    } else {
        return 0;
    }
}

    int findXOR(int l, int r) 
    {
        return XORupto(r)^XORupto(l-1);
    }
};
