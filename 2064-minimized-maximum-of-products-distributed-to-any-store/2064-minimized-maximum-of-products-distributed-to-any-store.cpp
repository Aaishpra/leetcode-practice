class Solution {
public:
    bool isValid(vector<int> q,int mid,int n){
        int cnt=0;
        for(int x:q){
            if(x%mid==0){
                cnt+=x/mid;
            }
            else cnt+=x/mid+1;
        }
        return cnt<=n;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int lo=1,hi=*max_element(q.begin(),q.end());
        
        int res=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(q,mid,n)){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
};