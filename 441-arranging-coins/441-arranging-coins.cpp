class Solution {
public:
    int arrangeCoins(int n) {
        int cnt=0;
        for(int i=1;i<=n and n>0;i++){
            
            n-=i;
            cnt++;
        }
        return cnt;
    }
};