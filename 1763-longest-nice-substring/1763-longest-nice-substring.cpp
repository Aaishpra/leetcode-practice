class Solution {
public:
    bool helper(string s){
        
        for(char c:s){
            if(c<=92) c+=32;
            else c-=32;
            if(s.find(c)==string::npos)
                return false;
        }
        return true;
    }
    string longestNiceSubstring(string s) {
         string ans="";
        for(int i=0;i<s.length();i++)
        {
            string res="";
            res+=s[i];
            for(int j=i+1;j<s.length();j++)
            {
                res+=s[j];
                if(helper(res) && res.size()>ans.size())ans=res;
            }
        }
        return ans;
    }
};