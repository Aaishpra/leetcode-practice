class Solution {
public:
    int dp[501][501][2];
    int solve(vector<int> & nums,int i,int j,int chance){
        if(i>j)return 0;
        if(dp[i][j][chance]!=-1)return dp[i][j][chance];
        if(chance==0)return dp[i][j][chance]=max(nums[i]+solve(nums,i+1,j,1),nums[j]+solve(nums,i,j-1,1));
        else return dp[i][j][chance]=min(solve(nums,i+1,j,0),solve(nums,i,j-1,0));
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int sum=accumulate(piles.begin(),piles.end(),0);
        int alice=solve(piles,0,piles.size()-1,0);
        int bob=sum-alice;
        return alice>bob;
    }
};