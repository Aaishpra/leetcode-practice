class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int mx=0;
        int i=0,j=0;
        unordered_map<char,int> mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                mx=max(j-i+1,mx);
            }
            else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
               
                if(mp.size()==j-i+1){
                    mx=max(j-i+1,mx);
                }
            }
            j++;
        }
        return mx;
    }
};