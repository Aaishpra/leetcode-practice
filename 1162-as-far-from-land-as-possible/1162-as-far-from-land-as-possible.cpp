class Solution {
public:
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1};
    int maxDistance(vector<vector<int>>& grid) {
        int mx=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<grid.size() and ny<grid[0].size() and grid[nx][ny]==0){
                    q.push({nx,ny});
                    grid[nx][ny]=grid[x][y]+1;
                    mx=max(mx,grid[nx][ny]);
                }
            }
        }
        return mx-1;
    }
};