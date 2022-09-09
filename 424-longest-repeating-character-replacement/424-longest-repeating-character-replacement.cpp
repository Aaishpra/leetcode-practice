class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i=0,j=0;
        int res=0;
        int mx=0;
        while(j<s.size()){
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);
            if(j-i+1-mx<=k){
                res=max(res,j-i+1);
                j++;
            }
            else{
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return res;
    }
};