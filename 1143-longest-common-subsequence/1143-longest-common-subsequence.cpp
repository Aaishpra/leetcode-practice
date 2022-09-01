class Solution {
public:
    int dp[1002][1002];
    
    int lcs(string &x,string &y,int n,int m,vector<vector<int>> &dp){
        if(n==0 or m==0) return dp[n][m]= 0;
        if(dp[n][m]!=-1) return dp[n][m];    
        
        if(x[n-1]==y[m-1])
            dp[n][m]=1+lcs(x,y,n-1,m-1,dp);
        else 
            dp[n][m]=max(lcs(x,y,n-1,m,dp),lcs(x,y,n,m-1,dp));
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return lcs(text1,text2,text1.size(),text2.size(),dp);
    }
};