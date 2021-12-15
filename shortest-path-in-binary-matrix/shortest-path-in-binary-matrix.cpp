class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int r=grid.size();
//         int c=grid[0].size();
//         int ans=0;
//         queue<pair<int,int>> q;
//         vector<int> dx = {1,0,-1,0,1,-1,1,-1};
//         vector<int> dy = {0,1,0,-1,-1,1,1,-1};
        
//         vector<vector<int>> vis(r,vector(c,0));
//         if(grid[0][0] ==1 or grid[r-1][c-1]==0) return -1;
        
//         q.push({0,0});
//         vis[0][0]=1;
        
//         while(!q.empty()){
//             int steps=q.size();
//             ans++;
            
//             for(int i=0;i<steps;i++){
//              int x=q.front().first;
//              int y=q.front().second;
//             q.pop();
//                 if(x==r-1 and y==c-1) return ans;
            
//             for(int i=0;i<8;i++){
//                 int x1=x+dx[i];
//                 int y1=y+dy[i];
//                 if(x1>=0 and x1<r and y1>=0 and y1<c and vis[x1][y1]==0 and grid[x1][y1]==0){
//                     q.push({x1,y1});
//                     vis[x1][y1]=1;
//                 }
//             }
//             } 
//         }
//         return -1;
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> qu;
        vector<vector<bool>> visit(r,vector(c,false));
        
        if(grid[0][0] == 1 || grid[r-1][c-1] == 1){
            return -1;
        }
        
        qu.push(make_pair(0,0));
        visit[0][0] = true;
        
        while(!qu.empty()){
            int steps = qu.size();
            ans++;
            
            /*directions*/
            for(int i = 0;i < steps; ++i){
                int x = qu.front().first;
                int y = qu.front().second;
                qu.pop();
                if(x == r-1 && y == c-1){
                    return ans;
                }
                
                for(int j = 0;j < 8; ++j){
                    int x1 = x + d[j][0];
                    int y1 = y + d[j][1];
                    if(x1 >= 0 && x1 < r && y1 >= 0 && y1 < c){
                        if(!visit[x1][y1] && !grid[x1][y1]){
                            qu.push(make_pair(x1,y1));
                            visit[x1][y1] = true;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};