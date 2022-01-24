class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_map<char,int> mp;
        int res=0;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                res=max(res,j-i+1);
            }
            else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return res;
    }
};