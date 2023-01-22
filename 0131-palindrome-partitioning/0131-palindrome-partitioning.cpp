class Solution {
public:
    vector<vector<string>> res;
    bool ispalin(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int idx,string& ip,vector<string>& op){
        if(idx>=ip.size()){
            res.push_back(op);
            return;
        }
        
        for(int i=idx;i<ip.size();i++){
            if(ispalin(ip,idx,i)){
                op.push_back(ip.substr(idx,i-idx+1));
                solve(i+1,ip,op);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> op;
        solve(0,s,op);
        return res;
    }
};