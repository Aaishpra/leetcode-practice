class Solution {
public:
    int dp[202][202]={0};
    int dfs(vector<vector<int>> &matrix,int i,int j,int prev){
        if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size() or matrix[i][j]<=prev) return 0;
        if(dp[i][j]!=0)return dp[i][j];
        return dp[i][j]=1+max({dfs(matrix,i-1,j,matrix[i][j]),dfs(matrix,i+1,j,matrix[i][j]),dfs(matrix,i,j-1,matrix[i][j]),dfs(matrix,i,j+1,matrix[i][j])});
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int mx=0;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mx=max(mx,dfs(matrix,i,j,-1));
            }
        }
        return mx;
    }
};