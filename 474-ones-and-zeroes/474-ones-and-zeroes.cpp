class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1)));
       
        for(int i=1;i<strs.size()+1;i++){
            int ones=count(strs[i-1].begin(),strs[i-1].end(),'1');
            int zeros=strs[i-1].size()-ones;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(j-zeros>=0 and k-ones>=0){
                        dp[i][j][k]=max(1+dp[i-1][j-zeros][k-ones],dp[i-1][j][k]);
                    }
                    else dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};