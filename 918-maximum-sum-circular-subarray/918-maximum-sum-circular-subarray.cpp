class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur1=nums[0];
        int cur2=nums[0];
        int best1=nums[0];
        int best2=nums[0];
        int total=nums[0];
        
        for(int i=1;i<nums.size();i++){
            total+=nums[i];
            cur1=max(cur1+nums[i],nums[i]);
            best1=max(cur1,best1);
            cur2=min(cur2+nums[i],nums[i]);
            best2=min(cur2,best2);
        }
        return total==best2?best1:max(best1,total-best2);
    }
};