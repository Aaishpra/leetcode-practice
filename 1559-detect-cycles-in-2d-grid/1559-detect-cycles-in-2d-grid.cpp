class Solution {
public:
    bool backtrack(vector<vector<char>>& ar,char target,int i,int j,vector<vector<int>> & vis,int n,int m){  
        if(i<0 or j<0 or i>=n or j>=m or ar[i][j]!=target) return false;
        if(vis[i][j]==1) return true;
        vis[i][j]=1;
        ar[i][j]='#';
        bool ans=backtrack(ar,target,i+1,j,vis,n,m) or backtrack(ar,target,i-1,j,vis,n,m) or backtrack(ar,target,i,j+1,vis,n,m) or backtrack(ar,target,i,j-1,vis,n,m);
        ar[i][j]=target;
        return ans;
        
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and backtrack(grid,grid[i][j],i,j,vis,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};