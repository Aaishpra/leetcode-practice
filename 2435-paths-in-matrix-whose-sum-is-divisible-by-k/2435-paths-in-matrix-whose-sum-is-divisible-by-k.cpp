class Solution {
public:
    int mod=1e9+7;

    
    int dfs(vector<vector<int>>& grid,int i,int j,int sum,int k,vector<vector<vector<int>>>& dp){
        if(i==0 and j==0) return sum%k==0?1:0;
        
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        
        int left=0,right=0;
        
        if(i-1>=0 and j>=0) left= dfs(grid,i-1,j,(sum+grid[i-1][j])%k,k,dp);
        if(j-1>=0 and i>=0) right=dfs(grid,i,j-1,(sum+grid[i][j-1])%k,k,dp);
        return dp[i][j][sum]=(left+right)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
     
        int m=grid.size();
        int n=grid[0].size();
          vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return dfs(grid,grid.size()-1,grid[0].size()-1,grid[m-1][n-1]%k,k,dp);
    }
};