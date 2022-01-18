class Solution {
public:
    int scoreOfParentheses(string s) {
     
        stack<int> mystack;
        mystack.push(0);
        for(char c:s){
            if(c=='(') mystack.push(0);
            else if(c==')'){
                int val=0;
                int tmp=mystack.top();
                mystack.pop();
                if(tmp>0)val=2*tmp;
                else val=1;
                mystack.top()+=val;
            }
        }
        return mystack.top();
    }
};