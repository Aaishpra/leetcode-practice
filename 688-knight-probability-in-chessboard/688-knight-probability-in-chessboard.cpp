class Solution {
public:
    double dp[26][26][101];
    int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    
    double solve(int x,int y,int k,int n){
        if(x<0 or y<0 or y>=n or x>=n)return 0;
        if(k<=0)return 1;
        if(dp[x][y][k]!=0)return dp[x][y][k];
        double p=0;
        for(int i=0;i<8;i++){
            p+=solve(x+dx[i],y+dy[i],k-1,n);
        }
        return dp[x][y][k]=p/8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        memset(dp,0,sizeof(dp));
        return solve(row,column,k,n);
    }
};