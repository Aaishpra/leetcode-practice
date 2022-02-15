class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        
        for(int i=0;i<s.size();i+=k){
            string t=s.substr(i,k);
            if(t.size()==k){
                ans.push_back(t);
                continue;
            }
            int l=t.size();
            for(int j=0;j<(k-l);j++){
                t+=fill;
            }
            ans.push_back(t);
        }
        return ans;
    }
};