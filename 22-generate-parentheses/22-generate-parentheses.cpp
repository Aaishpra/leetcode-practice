class Solution {
public:
    vector<string> res;

    void solve(int open,int close,string op){
        if(close==0 and open==0){
            res.push_back(op);
            return;
        }
        if(open!=0){
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1);
        }
        if(close>open){
            string op1=op;
            op1.push_back(')');
            solve(open,close-1,op1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string op="";
        solve(n,n,op);
        return res;
    }
};