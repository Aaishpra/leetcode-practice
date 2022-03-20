class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        int ans=10;
        int start=9,cur=9;
        while(n-->1 and start){
            cur*=start;
            start--;
            ans+=cur;
        }
        return ans;
    }
};