class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
     int n=grid.size();
     int m=grid[0].size();
        if(n==0)return 0;
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        //int t[n][m];
        vector<vector<int>> t(n,vector<int>(m,0));
        t[0][0]=grid[0][0];
       
        
        for(int i=1;i<m;i++){
            t[0][i]=grid[0][i]+t[0][i-1];
        }
         for(int i=1;i<n;i++){
            t[i][0]=grid[i][0]+t[i-1][0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                t[i][j]=grid[i][j]+min(t[i-1][j],t[i][j-1]);
            }
        }
        return t[n-1][m-1];
    }
};