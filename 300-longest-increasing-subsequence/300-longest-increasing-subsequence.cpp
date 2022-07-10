class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     vector<int> bp;
        
        for(int i=0;i<nums.size();i++){
            if(bp.empty() or bp[bp.size()-1]<nums[i]){
                bp.push_back(nums[i]);
            }
            else {
                auto it=lower_bound(bp.begin(),bp.end(),nums[i]);
                *it=nums[i];
            }
        }
        return bp.size();
    }
};