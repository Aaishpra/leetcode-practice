class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(2));
        if(arr.size()==0)return 0;
        int n=arr.size(), mxlen=0;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                dp[i][0]=dp[i-1][1]+1;
                mxlen=max(dp[i][0],mxlen);
            }
            else if(arr[i-1]>arr[i]){
                dp[i][1]=dp[i-1][0]+1;
                mxlen=max(dp[i][1],mxlen);
            }
        }
    return mxlen + 1;
        
    }
};