class Solution {
public:
    int tribonacci(int n) {
        if(n<2) return n;
        if(n==2) return n-1;
        int t0=0;
        int t1=1;
        int t2=1;
        int t=0;
        for(int i=3;i<n+1;i++){
            t= t0 + t1+ t2;
            t0=t1;
            t1=t2;
            t2=t;
        }
        return t;
    }
};