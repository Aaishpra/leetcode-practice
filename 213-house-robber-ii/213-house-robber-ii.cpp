class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        if(nums.size()==1)return nums[0];
        return max(solve(nums1),solve(nums2));
    }
    int solve(vector<int>&nums){
        vector<int> dp(nums);
        if(nums.size()==1)return nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};