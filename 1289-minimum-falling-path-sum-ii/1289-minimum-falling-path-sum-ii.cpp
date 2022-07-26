class Solution {
public:
   int dp[210][210];
int n;
int help(int i , int j , vector<vector<int>>& a)
{
    if(i<0 or i>=n or j< 0 or j>=n)  return 0;
    int &ans = dp[i][j];
    if(ans != INT_MAX)   return ans;
    // ans = INT_MAX;
    for(int c=0;c<n;c++)
    {
        if(c == j and i!=0)
            continue;
        ans = min(ans , a[i][c] + help(i+1 , c , a));
    }
    return ans ;
}

int minFallingPathSum(vector<vector<int>>& a) 
{
    n = a.size();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j] = INT_MAX;
    return help(0,0,a);
}
};