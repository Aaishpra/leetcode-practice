class Solution {
public:
    bool isValid(vector<int>& nums,int mid,int m,int k){
        int wn=0;
        for(int num:nums){
            if(num<=mid) wn++;
            else if(num>mid)wn=0;
            if(wn==k){
                m--;
                wn=0;
            }
            if(m==0)return true;
        }
        return false;
    }
    int minDays(vector<int>& nums, int m, int k) {
        if(m*k>nums.size()) return -1;
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());
        int res=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isValid(nums,mid,m,k)){
                res=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;
    }
};