class Solution {
public:
    int nextGreaterElement(int n) {
        string temp=to_string(n);
        stack<int> stk;
        int prev;
        for(int i=temp.size();i>=0;i--){
            if(!stk.empty() and temp[i]<temp[stk.top()]){
                while(!stk.empty() and temp[i]<temp[stk.top()]){
                    prev=stk.top();
                    stk.pop();
                }
                swap(temp[i],temp[prev]);
                reverse(temp.begin()+i+1,temp.end());
                break;
            }
            stk.push(i);
        }
        long long res = stoll(temp);
        return (res>INT_MAX || (int)res==n)?-1:(int)res;
    }
};