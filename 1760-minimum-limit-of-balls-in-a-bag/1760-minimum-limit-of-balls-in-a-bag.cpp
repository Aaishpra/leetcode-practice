class Solution {
public:
    bool isValid(vector<int>& nums,int m,int mid){
        int x=0;
        for(int n:nums){
            x+=n/mid;
            if(n%mid==0)x--;
        }
        return x<=m;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
    int lo=1, hi=*max_element(nums.begin(),nums.end());
        int res=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(nums,maxOperations,mid)){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
};