class Solution {
public:
    int dp[503][503];
    
    int solve(string x,string y,int n,int m){
        if(n==0){
            dp[n][m]=m;
        }
        else if(m==0){
            dp[n][m]=n;
        }
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        else if(x[n-1]==y[m-1])
            dp[n][m]=solve(x,y,n-1,m-1);
        else dp[n][m]=min(solve(x,y,n-1,m-1),min(solve(x,y,n-1,m),solve(x,y,n,m-1)))+1;
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return solve(word1,word2,word1.size(),word2.size());
    }
};