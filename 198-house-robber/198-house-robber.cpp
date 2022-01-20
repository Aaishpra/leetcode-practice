class Solution {
public:
    
    // int helper(vector<int>& nums, int i, int n){
    //     if(i>=n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int chosen = nums[i]+ helper(nums,i+2,n);
    //     int not_chosen= helper(nums,i+1,n);
    //     return dp[i]= max(chosen,not_chosen);
    // }
     int helper(vector<int>& q,vector<int>& dp, int i,int n){
       if(i>=n) return 0;
       if(dp[i]!=-1) return dp[i];
       int t   = q[i] + helper(q,dp ,i+2, n);
       int n_t = helper(q,dp,i+1,n);
       return dp[i]= max(t,n_t);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size(),-1);
        return helper(nums,dp,0,n);
    }
};