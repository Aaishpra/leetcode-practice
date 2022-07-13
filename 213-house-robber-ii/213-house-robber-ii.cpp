class Solution {
public:
    int rob(vector<int>& nums) {
     //two times house robber;
        if(nums.size()==1)return nums[0];
        
        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);
        
        return max(solve(numsA),solve(numsB));
    }
    int solve(vector<int> &nums){
        vector<int> dp(nums);
        int n=nums.size();
            if(n==1)return nums[0];
        dp[1]=max(nums[1],nums[0]);
        
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};