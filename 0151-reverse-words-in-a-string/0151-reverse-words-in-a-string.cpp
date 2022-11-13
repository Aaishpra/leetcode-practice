class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word;
        vector<string> res;
        while(ss>>word){
            res.push_back(word);
        }
        string ans="";
        for(int i=res.size()-1;i>=0;i--)
            ans=ans+res[i]+' ';
        ans.pop_back();
        return ans;
    }
};