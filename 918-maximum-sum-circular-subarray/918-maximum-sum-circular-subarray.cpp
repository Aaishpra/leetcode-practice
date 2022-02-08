class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
          int curr=nums[0];
        int best=nums[0];
        int total=nums[0];
        int mine=nums[0];
        int best1=nums[0];
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
            total+=nums[i];
            curr=max(curr+nums[i],nums[i]);
            best=max(curr,best);
            mine=min(mine+nums[i],nums[i]);
            best1=min(mine,best1);
        }
        
      
        return total==best1?best:max(best,total-best1);
    }
};