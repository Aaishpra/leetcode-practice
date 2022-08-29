class Solution {
public:
    static bool mysort(vector<int> &a,vector<int>& b){
        return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(), mysort);
        vector<int> dp(pairs.size(),1);
        for(int i=0;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};