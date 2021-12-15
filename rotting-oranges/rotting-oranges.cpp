class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int n=grid.size();
        int m=grid[0].size();
        vector<int> dir={-1,0,1,0,-1};
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        int ans=-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int x1=x+dir[i];
                    int y1=y+dir[i+1];
                    if(x1>=0 and x1<n and y1>=0 and y1<m and grid[x1][y1]==1){
                        q.push({x1,y1});
                        fresh--;
                        grid[x1][y1]=2;
                    }
                }
            }
            ans++;
        }
if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
    }
};










































