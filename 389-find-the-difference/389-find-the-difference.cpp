class Solution {
public:
    char findTheDifference(string s, string t) {
    unordered_map<char,int> mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        for(int j=0;j<s.length();j++){
            mp[s[j]]--;
        }
        for(auto m:mp){
            if(m.second==1){
                return m.first;
            }
        }
        return 'a';
    }
};