class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n<=0)return 0;  
        int mn=INT_MAX;
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i*i<=n;i++){
            mn=min(mn,solve(n-i*i,dp));
        }
        return dp[n]= mn+1;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
        
    }
};