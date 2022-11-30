class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int cnt=0;
        while(i<s.size() and j<t.size()){
            if(s[i]==t[j]){
                cnt++;
                j++;
                i++;
            }
             else i++;
        }
        return t.size()-cnt;
    }
};