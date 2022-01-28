class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<int> &vis,int node){
        vis[node]=1;
        for(int i=0;i<grid.size();i++){
           // if(i==node)continue;
             if(vis[i]==0 and grid[node][i]){
                dfs(grid,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> vis(n,0);
        
        int count=0;
        
        for(int i=0;i<n;i++){
            {
                if(vis[i]==0){
                    dfs(grid,vis,i);
                    count++;
                }
            }
        }
        return count;
    }
};