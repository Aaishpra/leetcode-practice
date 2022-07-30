class Solution {
public:
    int numRollsToTarget(int n, int f, int target) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int k=1;k<=f;k++){
                    if(k<=j){
                        dp[i][j]= ((dp[i][j])%mod+(dp[i-1][j-k])%mod)%mod;
                    }
                    
                }
            }
        }
        return dp[n][target];
    }
};