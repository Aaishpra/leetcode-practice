class Solution {
    private:
    void dfs(vector<vector<char>> &grid,int i , int j){
        if(i>=0 and i<grid.size() and j>=0 and j<grid[0].size() and grid[i][j]=='1'){
        grid[i][j]='0';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);}
    }
public:
    int numIslands(vector<vector<char>>& grid) {
     int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};