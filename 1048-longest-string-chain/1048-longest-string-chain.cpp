class Solution {
public:
    bool isPred(string& a,string& b){
        if(a.size()-b.size()!=1) return false;
        int i=0,j=0;
        while(i<a.size() and j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else i++;
        }
        return j==b.size();
    }
    static bool cmp(string a,string b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int> dp(n,1);
        int res=1;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(isPred(words[i],words[j])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
                    res=max(res,dp[i]);
        }
        return res;
    }
};