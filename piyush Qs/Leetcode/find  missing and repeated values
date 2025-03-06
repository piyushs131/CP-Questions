class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mpp;
        for (auto &row : grid) {
            for (int num : row) {
                mpp[num]++;
            }
        }
        vector<int>final(2);
        for(int i=0;i<grid.size()*grid.size();i++)
        {
            auto it=mpp.find(i+1);
            if(it!=mpp.end())
            {
                if(mpp[i+1]==2)final[0]=i+1;
            }
            else final[1]=i+1;
        }
        return final;
    }
};