class Solution {
public:
    bool isValid(int m,int n,int k, int mid){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt+=min(mid/i,n);
        }
        return cnt>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int lo=1,hi=m*n;
            int res=-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(m,n,k,mid)){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return lo;
    }
};