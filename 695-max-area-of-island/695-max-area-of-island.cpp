class Solution {
private:
    int dfs(vector<vector<int>> &grid,int i, int j){
        int d=0;
        if(i>=0 and i<grid.size() and j>=0 and j<grid[0].size() and grid[i][j]==1){
            grid[i][j]=0;
            int d1=dfs(grid,i+1,j);
            int d2=dfs(grid,i-1,j);
            int d3=dfs(grid,i,j+1);
            int d4=dfs(grid,i,j-1);
            d=1+d1+d2+d3+d4;
            
        }
        return d;
    }
    public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                res=max(res,dfs(grid,i,j));}
            }
        }
        return res;
    }
};