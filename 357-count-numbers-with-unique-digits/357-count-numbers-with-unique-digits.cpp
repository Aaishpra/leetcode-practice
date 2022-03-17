class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int ans=10; // for 0 digit = 1 and for 1 digit  unique digits = 9 so total = U(0) + U(1) = 10
        int start=9;
        int current=9;
        
        while(n-->1 and start){
            current*=start;
            start--;
            ans+=current;
        }
        return ans;
    }
};