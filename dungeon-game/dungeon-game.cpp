class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        int t[n][m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 and j==m-1) t[i][j]=min(0,dungeon[i][j]);
                else if(i==n-1)t[i][j]=min(0,dungeon[i][j]+t[i][j+1]);
                else if(j==m-1)t[i][j]=min(0,dungeon[i][j]+t[i+1][j]);
                else t[i][j]=min(0,dungeon[i][j]+max(t[i+1][j],t[i][j+1]));
            }
        }
        return abs(t[0][0])+1;
    }
};