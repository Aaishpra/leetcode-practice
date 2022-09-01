class Solution {
public:
    //int dp[47];
    int climb(int n,vector<int>& dp){
         if(n<=2)
            return dp[n]= n;
        if(dp[n]!=-1)return dp[n];
        int ans =climb(n-1,dp)+climb(n-2,dp);
        return dp[n]=ans;
    }
    int climbStairs(int n) {
    vector<int> dp(n+1,-1);
        return climb(n,dp);
    }
};