class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { 
        vector<int> dp;
        
        for(int n:nums){
            if(dp.empty() or dp.back()<n) dp.push_back(n);
            else{
                auto it = lower_bound(dp.begin(),dp.end(),n);
                *it=n;
            }
        }
        return dp.size();
    }
};