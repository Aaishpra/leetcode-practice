class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> str;
        for(char c=s[0];c<=s[3];c++){
            for(char r=s[1];r<=s[4];r++){
                str.push_back({c,r});
            }
        }
        return str;
    }
};