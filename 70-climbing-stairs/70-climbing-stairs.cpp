class Solution {
public:
    int climbStairs(int n) {
       if(n<=2)return n;
        int f=0,f1=1,f2=2;
        for(int i=3;i<=n;i++){
            f=f1+f2;
            f1=f2;
            f2=f;
        }
        return f;
    }
};