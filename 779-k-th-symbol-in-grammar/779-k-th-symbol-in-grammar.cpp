class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1 or n==1) return 0;
        int mid=pow(2,n-2);
        if(k<=mid) return kthGrammar(n-1,k)==0?0:1;
        else return kthGrammar(n-1,k-mid)==0?1:0;
    }
};