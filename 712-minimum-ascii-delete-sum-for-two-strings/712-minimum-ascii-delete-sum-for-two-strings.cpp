class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
     vector<vector<int>> dp(n+1,vector<int>(m+1));
        
       for(int i=1 ; i<n+1; i++)                 
        dp[i][0] = dp[i-1][0] + s1[i-1];

    for(int j=1; j<m+1; j++)                
        dp[0][j] = dp[0][j-1] + s2[j-1];
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else 
                    dp[i][j]=min(int(s1[i-1])+dp[i-1][j],int(s2[j-1])+dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};