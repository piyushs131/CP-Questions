#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        deque<int> n;
        deque<int> p;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <0) n.push_back(nums[i]);
            else p.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(i%2 ==0){
                nums[i]=p.front();
                p.pop_front();
            }
            else{
                nums[i]=n.front();
                n.pop_front();
            }
        }
        return nums;
    }
};