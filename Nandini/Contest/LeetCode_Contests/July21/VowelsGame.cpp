#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
    bool doesAliceWin(string s) 
    {
       int n = s.length();
       unordered_set<int> states;

    // Calculate the state of the string with respect to vowels
    int current_state = 0;
    states.insert(current_state);

    for (char c : s) {
        if (isVowel(c)) {
            current_state ^= 1; // Toggle the state for each vowel(XOR)
        }
        states.insert(current_state);
    }

    // Check if there's any state with an odd number of vowels
    for (int state : states) {
        if (state % 2 == 1) 
        {
            return true; 
        }
    }
    return false; 
}
};