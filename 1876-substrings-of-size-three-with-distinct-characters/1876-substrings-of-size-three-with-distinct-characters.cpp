class Solution {
public:
    int countGoodSubstrings(string s) {
    int cnt=0;
        for(int i=2;i<s.size();i++){
            if(s[i]!=s[i-1] and s[i]!=s[i-2] and s[i-1]!=s[i-2])
                cnt++;
        }
        return cnt;
    }
};