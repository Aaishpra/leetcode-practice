class Solution {
    public:
vector<string>ans;
  void solve(int close,int open,string op)
  {
    if(close==0 and open == 0)
    {
      ans.push_back(op);
      return;
    }
    if(open!=0)
    {
      string op1=op;
      op1.push_back('(');
      solve(close,open-1,op1);
    }
    if(close>open)
    {
      string op2=op;
      op2.push_back(')');
      solve(close-1,open,op2);
    }
  }

    vector<string> generateParenthesis(int n) {
      int close=n;
      int open=n;
      string op="";
      solve(close,open,op);
      return ans;
    }
};