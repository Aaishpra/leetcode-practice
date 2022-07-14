class Solution {
public:
   
    int findMaxForm(vector<string>& strs, int m, int n) {
        int t=strs.size();
         vector<vector<vector<int>>> dp(t+1,vector<vector<int>>(m+1,vector<int>(n+1)));
            
        for(int i=1;i<t+1;i++){
            int cz=count(strs[i-1].begin(),strs[i-1].end(),'0');
            int co=strs[i-1].size()-cz;
            for(int j=0;j<m+1;j++){
                for(int k=0;k<n+1;k++){
                    if(j-cz>=0 and k-co>=0){
                        dp[i][j][k]=max(1+dp[i-1][j-cz][k-co],dp[i-1][j][k]);
                    }
                    else dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
        return dp[t][m][n];
    }
};