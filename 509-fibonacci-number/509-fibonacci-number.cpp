class Solution {
public:
    int fib(int n) {
        int f=0;
        int f1=1;
        int f2=0;
        if(n<2)return n;
        for(int i=2;i<=n;i++){
           f2=f+f1;
            f=f1;
            f1=f2;
        }
        return f2;
    }
};