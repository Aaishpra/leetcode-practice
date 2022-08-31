class Solution {
public:
    vector<int> LIS(vector<int> &nums){
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp;
    }
     vector<int> LDS(vector<int> &nums){
        vector<int> dp(nums.size(),1);
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        
        vector<int> inc=LIS(nums);
        vector<int> dec=LDS(nums);
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(inc[i]==1 or dec[i]==1){
                continue;
            }
            else {
                ans=max(ans,inc[i]+dec[i]-1);
            }
        }
        return nums.size()-ans;
    }
};