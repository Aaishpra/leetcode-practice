class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<bool>& vis,int node){
        vis[node]=true;
        for(int i=0;i<grid.size();i++){
            if(i==node) continue;
            if(grid[node][i] and !vis[i]){
                dfs(grid,vis,i);
            }
        }
        }
    
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<grid.size();i++){
            {
               if(!vis[i]){
                    dfs(grid,vis,i);
                    count++;
                }
            }
        }
        return count;
    }
};






















