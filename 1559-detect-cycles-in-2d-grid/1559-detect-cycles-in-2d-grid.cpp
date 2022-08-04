class Solution {
public:
    bool solve(vector<vector<char>>& grid,vector<vector<int>>& vis,char target,int i,int j){
        int n=grid.size(),m=grid[0].size();
        if(i<0 or j<0 or j>=m or i>=n or grid[i][j]!=target) return false;
        if(vis[i][j]==1) return true;
        vis[i][j]=1;
        grid[i][j]='#';
        bool ans=solve(grid,vis,target,i-1,j) or solve(grid,vis,target,i+1,j) or solve(grid,vis,target,i,j-1) or solve(grid,vis,target,i,j+1);
        grid[i][j]=target;
        return ans;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and solve(grid,vis,grid[i][j],i,j))
                    return true;
            }
        }
        return false;
    }
};