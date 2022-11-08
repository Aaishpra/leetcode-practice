class Solution {
public:
    string makeGood(string s) {
        string res;
        
        for(int i=0;i<s.size();i++){
        res.push_back(s[i]);
            while(res.size()> 0 and( res.back()==s[i+1]-32 or res.back()==s[i+1]+32))
                res.pop_back() ,i++;
        }
        return res;
    }
};