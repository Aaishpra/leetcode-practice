class Solution {
public:
    double myPow(double x, int n) {
        double ans;
        if(n==0)return 1;
        if(n%2==0){
            double d=pow(x,n/2);
            ans=d*d;
        }
        else if(n%2!=0){
            ans=x*pow(x,n-1);
        }
        return ans;
    }
};