class Solution {
public:
    string thousandSeparator(int n) {
        string res=to_string(n);
        int sz=res.size();
        int i=sz-3;
        while(i>0){
            res.insert(i,".");
            i-=3;
        }
        return res;
    }
};