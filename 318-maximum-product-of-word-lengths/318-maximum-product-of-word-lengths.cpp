class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        bitset<26> bs[n+1];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                bs[i]|= 1<<(words[i][j]-'a');
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((bs[i]&bs[j])==0)
                {ans=max(ans,(int)words[i].length()*(int)words[j].length());}
            }
        }
        return ans;
    }
};