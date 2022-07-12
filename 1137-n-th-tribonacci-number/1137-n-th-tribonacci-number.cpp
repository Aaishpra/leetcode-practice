class Solution {
public:
    int tribonacci(int n) {
        int t=0,t1=1,t2=1,tn=0;
        if(n<2)return n;
        if(n==2) return n-1;
        for(int i=3;i<=n;i++){
            tn=t+t1+t2;
            t=t1;
            t1=t2;
            t2=tn;
        }
        return tn;
    }
};