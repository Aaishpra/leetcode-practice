class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<n+1;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string word=s.substr(j,i-j);
                    if(find(wordDict.begin(),wordDict.end(),word)!=wordDict.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};