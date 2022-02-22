class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> dp(nums);
       // dp[0]=0;
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++){
            int val=nums[i];
            dp[i]=max(dp[i-1],val+dp[i-2]);
        }
        return dp.back();
    }
};