class Solution {
public:
    int dp[301][301];
    int solve(vector<int>& arr,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            int left=1,right=1;
            if(i-1>=0) left=arr[i-1];
            if(j+1<arr.size()) right=arr[j+1];
            int temp=solve(arr,i,k-1)+solve(arr,k+1,j)+left*arr[k]*right;
            ans=max(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(nums,0,nums.size()-1);
    }
};