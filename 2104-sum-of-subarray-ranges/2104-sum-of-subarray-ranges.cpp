class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int mine,maxe;
        long long res=0;
        for(int i=0;i<nums.size();i++){
            mine=nums[i], maxe=nums[i];
            for(int j=i;j<nums.size();j++){
                maxe=max(maxe,nums[j]);
                mine=min(mine,nums[j]);
                res+=maxe-mine;
            }
        }
        return res;
    }
};