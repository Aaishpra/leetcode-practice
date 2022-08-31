class Solution {
public:
    bool isLis(vector<string>& strs,int i,int j){
        for(int itr=0;itr<strs.size();itr++){
            if(strs[itr][j]>strs[itr][i])
                return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        
        int n=strs[0].size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isLis(strs,i,j)==true){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return n-*max_element(dp.begin(),dp.end());
    }
};