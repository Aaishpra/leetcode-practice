class Solution {
public:
    int minInsertions(string s) {
      string y=s;
        reverse(y.begin(),y.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                dp[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return n-dp[n][n];
    }
};
