class Solution {
public:
    int kthGrammar(int n, int k) {
     int mid=pow(2,n-1)/2;
        if( k==1 or n==1) return 0;
        
        else if(k<=mid) return kthGrammar(n-1,k);
        
        else if(k>mid) return !kthGrammar(n-1,k-mid);
        return 0;
    }
};