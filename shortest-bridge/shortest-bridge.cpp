class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]!=1) return 0;
        grid[i][j]=2;
        return 1+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
    }
    bool expand(vector<vector<int>>& grid,int i, int j,int cl){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size()) return 0;
        if(grid[i][j]==0) grid[i][j]=cl+1;
        return grid[i][j]==1;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int found=0;
        for(int i=0;i< n;i++){
            for(int j=0;j<m;j++){
                if(found==0) found=dfs(grid,i,j);
            }
        }
        for (int cl = 2; ; ++cl)
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid.size(); ++j) 
                if (grid[i][j] == cl && ((expand(grid, i - 1, j, cl) || expand(grid, i, j - 1, cl) || 
                    expand(grid, i + 1, j, cl) || expand(grid, i, j + 1, cl))))
                        return cl - 2;
        
    }
};