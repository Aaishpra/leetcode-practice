class Solution {
public:
    vector<string> ans;
    void solve(string ip,string op){
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        string op1,op2;
        op1=op,op2=op;
        if(isalpha(ip[0])){
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin());
        solve(ip,op1);
        solve(ip,op2);
        }
        else{
            string op1=op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin());
            solve(ip,op1);
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        string op="";
       solve(s,op);
        return ans;
    }
};