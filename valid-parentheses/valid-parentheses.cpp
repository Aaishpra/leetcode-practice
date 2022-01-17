class Solution {
public:
    bool isValid(string st) {
    stack<int> s;
        for(auto c: st){
            if(s.empty() or c=='(' or c=='{' or c=='['){
                s.push(c);
            }
            else {
                if( (c==')' and s.top()!='(') or (c==']' and s.top()!='[') or (c=='}' and s.top()!='{')) return false;
                s.pop();
            }
        }
        return s.empty();
            
    }
};