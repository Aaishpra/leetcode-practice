class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums,int idx,int target){
        if(target==0){
            return 1;
        }
        if(idx==-1) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int ans=solve(nums,idx-1,target);
        if(target>=nums[idx]){
            ans+=solve(nums,nums.size()-1,target-nums[idx]);
        }
        return dp[idx][target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        dp.resize(n,vector<int>(target+1,-1));
        
        return solve(nums,n-1,target);
    }
};