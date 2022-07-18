class Solution {
public:
    int dp[41][41];
    int solve(vector<int>& arr,int i, int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int left=arr[i],right=arr[j];
            for(int l=i;l<=k;l++) left=max(left,arr[l]);
            for(int r=k+1;r<=j;r++) right=max(right,arr[r]);
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+left*right;
            ans=min(ans,temp);
            
        }
        return dp[i][j]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof dp);
        return solve(arr,0,arr.size()-1);
    }
};