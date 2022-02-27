class Solution {
public:
    int mySqrt(int x) {
        int lo=1, hi=x;
         if(x==0 or x==1) return x;
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            if(mid*mid==x)return mid;
            else if(mid*mid<x)lo=mid+1;
            else hi=mid;
        }
        return lo-1;
    }
};